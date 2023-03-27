#include "Command.hpp"
#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

Privmsg::Privmsg(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Privmsg::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "PRIVMSG") {
    std::vector<std::string> params = Util::split(request, ' ');

    // 정해진 형식에 맞게 들어오지 않은 경우
    if (params.size() < 2) return (true);

    std::string target = params[0];
    std::string msg = params[1];
    for (size_t i = 2; i < params.size(); i++) msg += " " + params[i];
    std::string nickname = c.get_m_nickname();

    if (target[0] == '!' || target[0] == '&' || target[0] == '#' ||
        target[0] == '+')  // msg to Channel
    {
      try {
        Channel &ch = m_server->get_m_channel(target);
        try {
          // 해당 채널에 속해있는 경우
          // 클라이언트의 v 플래그가 꺼져있는 경우 전송 불가
          if (!ch.get_m_channelauth(nickname).get_m_oper() &&
              ch.get_m_channelauth(nickname).get_m_voice() == false)
            c.sendMsg(Response::errCannotSendToChan(ch.get_m_channel_name()));
          else
            ch.sendMsg(Response::privMsg(nickname, c.get_m_username(),
                                         c.get_m_hostname(), target, msg),
                       nickname);
        } catch (const std::exception &e) {
          // 해당 채널에 속해있지 않은 경우
          // 채널의 n 플래그가 켜져있는 경우 전송 불가
          if (ch.get_m_notice_flag() == true)
            c.sendMsg(Response::errCannotSendToChan(ch.get_m_channel_name()));
          else
            ch.sendMsg(Response::privMsg(nickname, c.get_m_username(),
                                         c.get_m_hostname(), target, msg),
                       nickname);
        }
        // 해당 채널이 존재하지 않는 경우
      } catch (const std::exception &e) {
        c.sendMsg(Response::errNoSuchChannel(cmd, target));
      }
    } else  // msg to user
    {
      try {
        Client &clnt = m_server->get_m_client(target);
        // 유저의 i 플래그가 켜져있는경우
        if (clnt.get_m_invisible_flag() == true)
          c.sendMsg(Response::errNoSuchNick(cmd, target));
        else {
          clnt.sendMsg(Response::privMsg(nickname, c.get_m_username(),
                                         c.get_m_hostname(), target, msg));
          if (c.get_m_invisible_flag() == true) c.set_m_invisible_flag(false);
        }
      } catch (const std::exception &e) {
        c.sendMsg(Response::errNoSuchNick(cmd, target));
      }
    };
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
