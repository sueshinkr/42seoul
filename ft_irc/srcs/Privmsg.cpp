#include "Command.hpp"

/*==============================
-----------generator------------
===============================*/

Privmsg::Privmsg(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Privmsg::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "PRIVMSG") {
    // something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}