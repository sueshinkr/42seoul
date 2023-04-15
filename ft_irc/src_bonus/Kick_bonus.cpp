#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

Kick::Kick(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Kick::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "KICK") {
    std::vector<std::string> params = Util::split(request, ' ');
    if (params.size() < 2) {
      c.sendMsg(Response::errNeedMoreParams(cmd));
      return (true);
    }
    if (params.size() > 3) return (true);
    std::vector<std::string> channels = Util::split(params[0], ',');
    std::vector<std::string> users = Util::split(params[1], ',');
    std::vector<std::string> my_channels = c.get_m_channel();
    std::string comment;
    if (params.size() == 3) comment = params[2];
    for (size_t i = 0; i < channels.size(); i++) {
      try {
        if (channels[i][0] != '#' && channels[i][0] != '&' &&
            channels[i][0] != '!' && channels[i][0] != '+')
          continue;
        Channel &channel = m_server->get_m_channel(channels[i]);
        try {
          if (!channel.get_m_channelauth(c.get_m_nickname()).get_m_oper()) {
            c.sendMsg(Response::errChaNoPrivsNeeded(channels[i]));
            return (true);
          }
        } catch (const std::exception &e) {
          c.sendMsg(Response::errNotOnChannel(channels[i]));
          return (true);
        }
        for (size_t j = 0; j < users.size(); j++) {
          try {
            Client &user = m_server->get_m_client(users[i]);
            try {
              channel.get_m_client(user.get_m_nickname());
            } catch (const std::exception &e) {
              c.sendMsg(Response::errUserNotInChannel(user.get_m_nickname(),
                                                      channels[i]));
              return (true);
            }
            std::vector<std::string> my_ch = user.get_m_channel();
            if (comment.compare(":") == 0)
              channel.sendMsg(
                  Response::kickMsg(c.get_m_nickname(), c.get_m_username(),
                                    c.get_m_hostname(), channels[i], users[i]));
            else
              channel.sendMsg(Response::kickMsg(
                  c.get_m_nickname(), c.get_m_username(), c.get_m_hostname(),
                  channels[i], users[i], comment));
            channel.del_m_client(user.get_m_nickname());
            user.del_m_channel(channels[i]);
            if (channel.get_numOfpeople() == 0) {
              m_server->del_m_ch_to_channel(channel.get_m_channel_name());
            }
          } catch (const std::exception &e) {
            channel.sendMsg(
                Response::errNoSuchNick(cmd, users[i]));  // Additional Function
          }
        }
      } catch (const std::exception &e) {
        c.sendMsg(Response::errNoSuchChannel(cmd, channels[i]));
      }
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}