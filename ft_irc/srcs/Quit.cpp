#include "Command.hpp"

/*==============================
-----------generator------------
===============================*/

Quit::Quit(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Quit::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "QUIT") {
    // something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}