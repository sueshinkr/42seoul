#include "Command.hpp"

/*==============================
-----------generator------------
===============================*/

Mode::Mode(Server &server)
    : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Mode::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "MODE") {
    //something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}