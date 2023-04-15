#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

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

bool Oper::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "OPER") {
    std::vector<std::string> params = Util::split(request, ' ');
    if (params.size() < 2) {
      c.sendMsg(Response::errNeedMoreParams(cmd));
      return (true);
    }
    if (params.size() > 2) return (true);
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
      c.sendMsg(
          Response::errNoSuchNick(cmd, nickname));  // do not match NickName
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}