#include "Command.hpp"

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
  if (cmd == "PONG") {
    // something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}