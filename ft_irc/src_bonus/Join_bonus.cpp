#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

Join::Join(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Join::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "JOIN") {
    std::vector<std::string> params = Util::split(request, ' ');
    if (params.size() < 1) {
      c.sendMsg(Response::errNeedMoreParams(cmd));
      return (true);
    }
    if (params.size() > 2)
      return (true);
    else if (params.size() == 1 && !params[0].compare("0")) {
      // Leave All Channel
      while (!c.get_m_channel().empty()) {
        try {
          std::string chname = c.get_m_channel().back();
          Channel &ch = m_server->get_m_channel(chname);
          ch.sendMsg(Response::partChannel(c.get_m_nickname(),
                                           c.get_m_username(),
                                           c.get_m_hostname(), chname));
          ch.del_m_client(c.get_m_nickname());
          c.del_m_channel(chname);
          if (ch.get_numOfpeople() == 0) m_server->del_m_ch_to_channel(chname);
        } catch (const std::exception &e) {
          ;
        }
      }
      return (true);
    }
    std::vector<std::string> channels = Util::split(params[0], ',');
    std::vector<std::string> keys;
    if (params.size() == 2) keys = Util::split(params[1], ',');
    for (size_t i = 0; i < channels.size(); i++) {
      try {
        if (channels[i][0] != '#' && channels[i][0] != '&' &&
            channels[i][0] != '!' && channels[i][0] != '+')
          continue;
        Channel &channel = m_server->get_m_channel(channels[i]);
        try {
          channel.get_m_client(c.get_m_nickname());
          continue;
        } catch (const std::exception &e) {
          ;
        }
        std::vector<std::string> chusers;
        std::vector<Client *> chcls = channel.get_m_clients();
        for (size_t j = 0; j < chcls.size(); j++) {
          try {
            if (channel.get_m_channelauth(chcls[j]->get_m_nickname())
                    .get_m_oper())
              chusers.push_back("@" + chcls[j]->get_m_nickname());
            else if (channel.get_m_channelauth(chcls[j]->get_m_nickname())
                         .get_m_voice())
              chusers.push_back("+" + chcls[j]->get_m_nickname());
            else
              chusers.push_back(chcls[j]->get_m_nickname());
          } catch (const std::exception &e) {
            c.sendMsg(Response::errUserNotInChannel(chcls[j]->get_m_nickname(),
                                                    channels[i]));
            continue;
          }
        }
        if (channel.get_m_limit() >= 0 &&
            channel.get_m_limit() <= channel.get_numOfpeople())
          c.sendMsg(Response::errChannelIsFull(channels[i]));
        else if (i < keys.size()) {
          // Success Password
          if (channel.get_m_password() == keys[i]) {
            channel.add_client(c);
            chusers.push_back("+" + c.get_m_nickname());
            channel.sendMsg(
                Response::joinChannel(c.get_m_nickname(), c.get_m_username(),
                                      c.get_m_hostname(), channels[i]));
            channel.sendToMsg(Response::rplNamReply(channels[i], chusers),
                              c.get_m_nickname());
            channel.sendToMsg(Response::rplEndOfNames(channels[i]),
                              c.get_m_nickname());
            channel.sendMsg(Response::setChMode(
                c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
                channels[i], "+v " + c.get_m_nickname()));
          } else  // Wrong Password
            c.sendMsg(Response::errBadChannelKey(channels[i]));
        } else if (channel.get_m_password().empty()) {
          channel.add_client(c);
          chusers.push_back("+" + c.get_m_nickname());
          channel.sendMsg(
              Response::joinChannel(c.get_m_nickname(), c.get_m_username(),
                                    c.get_m_hostname(), channels[i]));
          channel.sendToMsg(Response::rplNamReply(channels[i], chusers),
                            c.get_m_nickname());
          channel.sendToMsg(Response::rplEndOfNames(channels[i]),
                            c.get_m_nickname());
          channel.sendMsg(Response::setChMode(
              c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
              channels[i], "+v " + c.get_m_nickname()));
        } else
          c.sendMsg(Response::errBadChannelKey(channels[i]));  // Wrong Password
      } catch (const std::exception &e) {
        // No Such Channel
        Channel *newch = new Channel(channels[i], c);
        newch->get_m_channelauth(c.get_m_nickname()).set_m_oper(true);
        m_server->set_m_ch_to_channel(channels[i], newch);
        if (i < keys.size())
          newch->set_m_password(keys[i]);
        else
          newch->set_m_password("");
        newch->set_m_limit(-1);
        newch->sendToMsg(
            Response::noticeMsg(
                "", c.get_m_username(), c.get_m_hostname(), channels[i],
                "You created the channel. You're the channel operator.\r\n"),
            c.get_m_nickname());
        newch->sendMsg(Response::joinChannel(c.get_m_nickname(),
                                             c.get_m_username(),
                                             c.get_m_hostname(), channels[i]));
        std::vector<std::string> chusers;
        chusers.push_back("@" + c.get_m_nickname());
        newch->sendToMsg(Response::rplNamReply(channels[i], chusers),
                         c.get_m_nickname());
        newch->sendToMsg(Response::rplEndOfNames(channels[i]),
                         c.get_m_nickname());
        newch->sendMsg(Response::setChMode(
            c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
            channels[i],
            "+v " + c.get_m_nickname()));
      }
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}