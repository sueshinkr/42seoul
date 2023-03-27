#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

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
    std::vector<std::string> params = Util::split(request, ' ');

    // 정해진 형식에 맞게 들어오지 않은 경우
    if (params.size() > 1) return (true);
    // 설정할 닉네임이 주어지지 않은 경우
    else if (params.size() < 1) {
      c.sendMsg(Response::errNoNicknameGiven());
      return (true);
    }

    std::string nickname = params[0];
    std::string prev_nickname = c.get_m_nickname();

    if (nickname[0] == '!' || nickname[0] == '&' || nickname[0] == '#' ||
        nickname[0] == '+') {
      c.sendMsg(Response::errErroneusNickname(nickname));
      return (true);
    }

    try {
      m_server->get_m_client(nickname);
      // 중복된 닉네임 반려
      c.sendMsg(Response::errNicknameInUse(nickname));
    } catch (const std::exception &error) {
      // 닉네임 변경의 경우
      if (!c.get_m_nickname().empty()) {
        m_server->del_m_nick_to_client(prev_nickname);
        c.set_m_nickname(nickname);
        m_server->set_m_nick_to_client(nickname, &c);

        std::vector<std::string> joined_ch = c.get_m_channel();
        // 채널에 접속중일 경우 해당 채널의 클라이언트들에게 모두 알림
        if (!joined_ch.empty())
          for (std::vector<std::string>::iterator iter = joined_ch.begin();
               iter != joined_ch.end(); iter++) {
            Channel &ch = m_server->get_m_channel(*iter);
            try {
              ch.change_m_name_to_client(prev_nickname, nickname);
              ch.sendMsg(Response::noticeNick(prev_nickname, c.get_m_nickname(),
                                              c.get_m_username(),
                                              c.get_m_hostname()));
            } catch (const std::exception &e) {
              // Something Error
              return (true);
            }
          }
        // 채널에 접속중이 아닐경우 자신에게만 알림
        else
          c.sendMsg(Response::noticeNick(prev_nickname, c.get_m_nickname(),
                                         c.get_m_username(),
                                         c.get_m_hostname()));
      } else {
        c.set_m_nickname(nickname);
        m_server->set_m_nick_to_client(nickname, &c);

        // 중복된 닉네임으로 연결 요구시 닉네임을 바꿔서 새로 연결 요구
        if (c.get_m_registered() == true) {
          c.sendMsg(Response::rplWelcome(c.get_m_nickname(), c.get_m_username(),
                                         c.get_m_hostname()));
          c.sendMsg(Response::rplYourHost());
          c.sendMsg(Response::noticeNick(prev_nickname, c.get_m_nickname(),
                                         c.get_m_username(),
                                         c.get_m_hostname()));
        }
      }
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
