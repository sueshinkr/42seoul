#include "Command.hpp"

/*==============================
-----------generator------------
===============================*/

Join::Join(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Join::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "JOIN") {
    // something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}