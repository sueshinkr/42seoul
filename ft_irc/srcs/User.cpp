#include "Command.hpp"
#include "Server.hpp"

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
    size_t prev = 0;
    size_t cur = request.find(" ");
    c.set_m_username(request.substr(prev, cur - prev));
    prev = cur + 1;

    cur = request.find(" ", prev);
    prev = cur + 1;

    cur = request.find(" ", prev);
    c.set_m_hostname(request.substr(prev, cur - prev));
    prev = cur + 1;

    cur = request.find(" ", prev);
    c.set_m_realname(request.substr(prev, cur - prev));

    if (!c.get_m_nickname().empty()) {
      c.sendMsg(Response::rplWelcome(c.get_m_nickname(), c.get_m_username(),
                                     c.get_m_hostname()));
      c.sendMsg(Response::rplYourHost());
    } else {
      m_server->del_m_fd_to_client(c.get_m_clnt_fd());
      epoll_ctl(c.get_m_epoll_fd(), EPOLL_CTL_DEL, c.get_m_clnt_fd(),
                &(m_server->get_m_events()));
      close(c.get_m_clnt_fd());
    }
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}