#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <sstream>
#include <string>

#include "Client.hpp"

class Server;

class Handler {
 public:
  virtual Handler *setNext(Handler *handler) = 0;
  virtual bool handle(std::string &cmd, std::string &request, Client &c) = 0;
};

class BaseHandler : public Handler {
 private:
  Handler *m_next;

 protected:
  Server *m_server;

 public:
  BaseHandler(Server &server);
  virtual Handler *setNext(Handler *handler);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
  std::vector<std::string> splitParam(std::string &request, char limiter);
};

#endif
