#include "Command.hpp"

/*==============================
-----------generator------------
===============================*/

Part::Part(Server &server)
    : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Part::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "PART") {
    //something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}