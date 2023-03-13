#include "Handler.hpp"
#include "Server.hpp"
#include <string>

/*==============================
-----------generator------------
===============================*/

BaseHandler::BaseHandler(Server &server) : m_next(NULL), m_server(&server) {}

/*==============================
--------private_function--------
===============================*/

/*==============================
---------public_function--------
===============================*/
/*
std::vector<std::string> splitParam(std::string &request,
                                    std::string &limiter) {
  std::vector<std::string> params;
  std::stringstream ss(request);
  std::string temp;

  while (std::getline(ss, temp, limiter)) {
    params.push_back(temp);
  }
  return (params);
}
*/
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