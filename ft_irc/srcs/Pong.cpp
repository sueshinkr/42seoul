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
    c.sendMsg(Response::responsePong());
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}
