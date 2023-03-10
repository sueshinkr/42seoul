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
  if (cmd == "CAP")
    return (true);

  if (cmd == "PASS") {
    // 패스워드가 틀린 경우
    if (request != m_server->get_m_password())
      response = Response::errNotRegistered(cmd);
    // 패스워드가 들어오지 않은 경우
  } else if (c.get_m_authorized() == false)
    response = Response::errNeedMoreParams(cmd);

  // 잘못된 패스워드의 경우 클라이언트와의 연결 해제
  if (!response.empty()) {
    c.sendMsg(response);
    m_server->del_m_fd_to_client(c.get_m_clnt_fd());
    epoll_ctl(c.get_m_epoll_fd(), EPOLL_CTL_DEL, c.get_m_clnt_fd(),
              &(m_server->get_m_events()));
    close(c.get_m_clnt_fd());
    return (false);
    // 올바른 패스워드가 들어온 경우
  } else if (c.get_m_authorized() == false) {
    c.set_m_authorized(true);
	return (true);
  }

  return (BaseHandler::handle(cmd, request, c));
}
