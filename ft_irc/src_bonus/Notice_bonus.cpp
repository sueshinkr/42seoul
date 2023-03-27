#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

Notice::Notice(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Notice::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "NOTICE") {
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
          if (ch.get_m_channelauth(nickname).get_m_oper() ||
              (ch.get_m_channelauth(nickname).get_m_voice() == true &&
               ch.get_m_notice_flag() == false))
            ch.sendMsg(Response::noticeMsg(nickname, c.get_m_username(),
                                           c.get_m_hostname(), target, msg),
                       nickname);
        } catch (const std::exception &e) {
          // 해당 채널에 속해있지 않은 경우
          if (ch.get_m_notice_flag() == false)
            // 채널의 n 플래그가 켜져있는 경우 전송 불가
            ch.sendMsg(Response::noticeMsg(nickname, c.get_m_username(),
                                           c.get_m_hostname(), target, msg));
        }
      } catch (const std::exception &e) {
      }
    } else  // msg to user
    {
      try {
        Client &clnt = m_server->get_m_client(target);
        if (clnt.get_m_invisible_flag() == true)
          ;
        else {
          clnt.sendMsg(Response::privMsg(nickname, c.get_m_username(),
                                         c.get_m_hostname(), target, msg));
          if (c.get_m_invisible_flag() == true) c.set_m_invisible_flag(false);
        }
      } catch (const std::exception &e) {
      }
    };
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}