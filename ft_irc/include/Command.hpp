#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "Handler.hpp"

class Pass : public BaseHandler {
 public:
  Pass(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class User : public BaseHandler {
 public:
  User(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Nick : public BaseHandler {
 public:
  Nick(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Oper : public BaseHandler {
 public:
  Oper(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Kill : public BaseHandler {
 public:
  Kill(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Notice : public BaseHandler {
 public:
  Notice(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Mode : public BaseHandler {
 public:
  Mode(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Privmsg : public BaseHandler {
 public:
  Privmsg(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Join : public BaseHandler {
 public:
  Join(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Part : public BaseHandler {
 public:
  Part(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Quit : public BaseHandler {
 public:
  Quit(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Kick : public BaseHandler {
 public:
  Kick(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Pong : public BaseHandler {
 public:
  Pong(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

class Whois : public BaseHandler {
 public:
  Whois(Server &server);
  virtual bool handle(std::string &cmd, std::string &request, Client &c);
};

#endif