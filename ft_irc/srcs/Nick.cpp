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
    if (nickname.empty()) {
      c.sendMsg(Response::errNoNicknameGiven());
      return (false);
    }

    try {
      m_server->get_m_client(nickname);
      if (!c.get_m_nickname().empty()) m_server->del_m_nick_to_client(c.get_m_nickname());
	  c.set_m_nickname(nickname);
      m_server->set_m_nick_to_client(nickname, c);
    } catch (const std::exception &error) {
      c.sendMsg(Response::errNicknameInUse(nickname));
      return (false);
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}