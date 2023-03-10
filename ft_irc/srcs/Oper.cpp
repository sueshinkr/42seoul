#include "Command.hpp"

/*==============================
-----------generator------------
===============================*/

Oper::Oper(Server &server)
    : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Oper::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "OPER") {
    //something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}