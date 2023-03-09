#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <list>
#include <string>

#define PASS 0
#define ERR -1
#define BACKLOG 5
#define EPOLL_SIZE 50

#include "Server.hpp"

class Client {
 private:
  int m_clnt_fd;
  int m_epoll_fd;

  std::string m_hostname;
  std::string m_nickname;
  std::string m_username;
  std::string m_realname;

  bool m_oper_flag;

 public:
  //Client();
  Client(Server &server);
  Client(int fd, int epollFd);

  Server &m_server;

  int sendMsg(std::string msg);

  int get_m_clnt_fd(void) const;
  int get_m_epoll_fd(void) const;
  std::string get_m_hostname(void) const;
  std::string get_m_nickname(void) const;
  std::string get_m_username(void) const;
  std::string get_m_realname(void) const;

  void set_m_hostname(std::string hostname);
  void set_m_nickname(std::string nickname);
  void set_m_username(std::string username);
  void set_m_realname(std::string realname);
  void set_m_oper_flag(bool flag);
};

#endif
