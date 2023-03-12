#include "Command.hpp"
#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

Whois::Whois(Server &server) : BaseHandler(server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

bool Whois::handle(std::string &cmd, std::string &request, Client &c) {
  if (cmd == "WHOIS") {
    c.sendMsg(Response::rplWhoisUser(request, c.get_m_username(),
                                     c.get_m_hostname(), c.get_m_realname()));
    return (true);
  }
  return (BaseHandler::handle(cmd, request, c));
}