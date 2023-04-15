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
    // 패스워드가 들어오지 않은 경우
    if (request.empty()) response = Response::errNeedMoreParams(cmd);
    // 패스워드가 틀린 경우
    else if (request != m_server->get_m_password())
      response = Response::errPassWDMismatch();
    // 인증되지 않았는데 다른 명령어가 먼저 들어온경우
  } else if (c.get_m_authorized() == false)
    response = Response::errNotRegistered(cmd);

  // 잘못된 경우 클라이언트와의 연결 해제
  if (!response.empty()) {
    c.sendMsg(response);
    m_server->disconnectClient(c.get_m_clnt_fd());
    return (true);
    // 올바른 패스워드가 들어온 경우
  } else if (c.get_m_authorized() == false) {
    c.set_m_authorized(true);
    return (true);
  }

  return (BaseHandler::handle(cmd, request, c));
}
