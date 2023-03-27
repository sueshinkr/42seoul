#include "Command_bonus.hpp"
#include "Server_bonus.hpp"

/*==============================
-----------generator------------
===============================*/

Quit::Quit(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Quit::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "QUIT") {
    std::vector<std::string> chlist = c.get_m_channel();
    for (std::vector<std::string>::iterator iter = chlist.begin();
         iter != chlist.end(); iter++) {
      Channel &ch = m_server->get_m_channel(*iter);
      if (request.empty())
        ch.sendMsg(Response::noticeQuit(c.get_m_nickname(), c.get_m_username(),
                                        c.get_m_hostname()));
      else
        ch.sendMsg(Response::noticeQuit(c.get_m_nickname(), c.get_m_username(),
                                        c.get_m_hostname(), request));
    }
    m_server->disconnectClient(c.get_m_clnt_fd());
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
