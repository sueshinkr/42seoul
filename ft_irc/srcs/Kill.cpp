#include "Command.hpp"

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
  if (cmd == "KILL") {
    // something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}