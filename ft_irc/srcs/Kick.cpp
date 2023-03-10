#include "Command.hpp"

/*==============================
-----------generator------------
===============================*/

Kick::Kick(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Kick::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "KICK") {
    // something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}