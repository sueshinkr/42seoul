#include "Command.hpp"
#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

Oper::Oper(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

// ERR_NOOPERHOST에 대한 의미 고려 필요 -> 서버가 OPER 연결을 거부할 수 있음.

bool Oper::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "OPER") {
    std::vector<std::string> params = splitParam(request, ' ');
    if (params.size() < 2) {
      c.sendMsg(Response::errNeedMoreParams(cmd));
      return (true);
    }
    std::string nickname = params[0];
    std::string password = params[1];

    try {
      if (password.compare("password"))
        c.sendMsg(Response::errPassWDMismatch());
      else {
        m_server->get_m_client(nickname).set_m_oper_flag(true);
        m_server->get_m_client(nickname).sendMsg(Response::rplYoureOper());
      }
    } catch (const std::exception &e) {
      ;  // do not match NickName
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}