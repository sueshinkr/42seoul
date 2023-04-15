#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

User::User(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool User::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "USER") {
    std::vector<std::string> params = Util::split(request, ' ');

    // 정해진 형식에 맞게 들어오지 않은 경우
    if (params.size() > 4)
      return (true);
    else if (params.size() < 4) {
      c.sendMsg(Response::errNeedMoreParams(cmd));
      return (true);
    }
    // 정상적으로 데이터가 주어진 경우
    else {
      c.set_m_username(params[0]);
      c.set_m_hostname(params[2]);
      if (params[3][0] == ':')
        c.set_m_realname(&params[3].at(1));
      else
        c.set_m_realname(params[3]);
      c.set_m_registered(true);
    }

    // 정상적으로 닉네임이 설정되어 있는 경우라면 등록
    if (!c.get_m_nickname().empty()) {
      c.sendMsg(Response::rplWelcome(c.get_m_nickname(), c.get_m_username(),
                                     c.get_m_hostname()));
      c.sendMsg(Response::rplYourHost());
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
