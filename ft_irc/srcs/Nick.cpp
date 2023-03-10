#include "Command.hpp"
#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

Nick::Nick(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Nick::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "NICK") {
    std::string nickname = request;
    std::string prev_nickname = c.get_m_nickname();

    // 닉네임이 설정되지 않은 경우
    if (nickname.empty()) {
      c.sendMsg(Response::errNoNicknameGiven());
      return (false);
    }

    try {
      m_server->get_m_client(nickname);

      // 닉네임 변경의 경우
      if (!c.get_m_nickname().empty()) {
        m_server->del_m_nick_to_client(prev_nickname);
        c.set_m_nickname(nickname);
        m_server->set_m_nick_to_client(nickname, c);

        std::vector<std::string> joined_ch = c.get_m_channel();
        // 채널에 접속중일 경우 해당 채널의 클라이언트들에게 모두 알림
        if (!joined_ch.empty())
          for (std::vector<std::string>::iterator iter = joined_ch.begin();
               iter != joined_ch.end(); iter++) {
            Channel ch = m_server->get_m_channel(*iter);
            ch.change_m_name_to_client(prev_nickname, nickname);
            ch.sendMsg(Response::rplSaveNick(prev_nickname, c.get_m_nickname(),
                                             c.get_m_username(),
                                             c.get_m_hostname()));
          }
        // 채널에 접속중이 아닐경우 자신에게만 알림
        else
          c.sendMsg(Response::rplSaveNick(prev_nickname, c.get_m_nickname(),
                                          c.get_m_username(),
                                          c.get_m_hostname()));
      }
      // 중복된 닉네임으로 연결 요구시 닉네임을 바꿔서 새로 연결 요구
      else {
        c.set_m_nickname(nickname);
        m_server->set_m_nick_to_client(nickname, c);

        if (c.get_m_registered() == true) {
          c.sendMsg(Response::rplWelcome(c.get_m_nickname(), c.get_m_username(),
                                         c.get_m_hostname()));
          c.sendMsg(Response::rplYourHost());
        }
        // 중복된 닉네임 반려
      }
    } catch (const std::exception &error) {
      c.sendMsg(Response::errNicknameInUse(nickname));
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
