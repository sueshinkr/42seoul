#include "Command.hpp"
#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

Kill::Kill(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Kill::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "kill") {
    if (!c.get_m_oper_flag()) {
      c.sendMsg(Response::errNoPrivileges());
    } else {
      size_t cur = request.find(" ");
      std::string target_nickname = request.substr(0, cur);
      std::string kill_msg = request.substr(cur + 1, std::string::npos);
      try {
        Client target = m_server->get_m_client(request.substr(0, cur));
        c.sendMsg(Response::rplKillDone(target_nickname, kill_msg));
        target.sendMsg(Response::noticeKill(c.get_m_nickname(),
                                            c.get_m_username(),
                                            c.get_m_hostname(), kill_msg));
        m_server->disconnectClient(target.get_m_clnt_fd());

      } catch (const std::exception &e) {
        c.sendMsg(Response::errNoSuchNick(cmd, target_nickname));
      }
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}