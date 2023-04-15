#include "Command.hpp"
#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

Pong::Pong(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Pong::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "PING") {
    std::vector<std::string> params = Util::split(request, ' ');
    if (params.size() > 1)
      return (true);
    else if (params.size() < 1) {
      c.sendMsg(Response::errNeedMoreParams(cmd));
      return (true);
    } else
      c.sendMsg(Response::responsePong());
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
