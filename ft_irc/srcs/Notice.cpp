#include "Command.hpp"

/*==============================
-----------generator------------
===============================*/

Notice::Notice(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Notice::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "NOTICE") {
    // something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}