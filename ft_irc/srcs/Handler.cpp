#include "Handler.hpp"
#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

BaseHandler::BaseHandler(Server &server)
    : m_next(NULL), m_server(&server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/

Handler *BaseHandler::setNext(Handler *handler) {
  this->m_next = handler;
  return (handler);
}

bool BaseHandler::handle(std::string &cmd, std::string &request, Client &c) {
  if (this->m_next) {
    return (this->m_next->handle(cmd, request, c));
  }
  return (false);
}