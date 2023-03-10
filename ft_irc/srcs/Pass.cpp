#include "Command.hpp"
#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

Pass::Pass(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Pass::handle(std::string &cmd, std::string &request, Client &c) {
  std::string response;
  if (cmd == "CAP") return (true);

  if (cmd == "PASS") {
    if (request != m_server->get_m_password())
      response = Response::errNotRegistered(cmd);
  } else if (c.get_m_authorized() == false)
    response = Response::errNeedMoreParams(cmd);

  if (!response.empty()) {
    c.sendMsg(response);
	m_server->del_m_fd_to_client(c.get_m_clnt_fd());
    epoll_ctl(c.get_m_epoll_fd(), EPOLL_CTL_DEL, c.get_m_clnt_fd(),
              &(m_server->get_m_events()));
    close(c.get_m_clnt_fd());
    return (false);
  } else if (c.get_m_authorized() == false) {
    c.set_m_authorized(true);
    return (true);
  }

  return (BaseHandler::handle(cmd, request, c));
}

/*

 response = ":" + m_server->get_m_serv_name() +
                     " 001 Welcome to the Internet Relay Network" +
                     c.get_m_nickname() + "!" + c.get_m_username
                 nick > !<user> @<host> "" send(c.get_m_clnt_fd(), ) std::cout
                            << "passsssssss\n";*/