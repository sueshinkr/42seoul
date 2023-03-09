#include "Command.hpp"

/*==============================
-----------generator------------
===============================*/

Whois::Whois(Server &server)
    : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Whois::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "WHOIS") {
    //something Send To Client
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}