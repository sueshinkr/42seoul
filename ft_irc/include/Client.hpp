#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

#define PASS 0
#define ERR -1
#define BACKLOG 5
#define EPOLL_SIZE 50

class Client {
 private:
  int m_clnt_fd;
  int m_epoll_fd;

  bool m_authorized;
  bool m_registered;

  std::string m_hostname;
  std::string m_nickname;
  std::string m_username;
  std::string m_realname;
  std::vector<std::string> m_channel;

  bool m_oper_flag;

 public:
  Client();
  Client(int fd, int epollFd);

  int sendMsg(std::string msg);

  int get_m_clnt_fd(void) const;
  int get_m_epoll_fd(void) const;
  bool get_m_authorized(void) const;
  bool get_m_oper_flag(void) const;
  bool get_m_registered(void) const;

  std::string get_m_hostname(void) const;
  std::string get_m_nickname(void) const;
  std::string get_m_username(void) const;
  std::string get_m_realname(void) const;
  std::vector<std::string> get_m_channel(void) const;

  void set_m_hostname(std::string hostname);
  void set_m_nickname(std::string nickname);
  void set_m_username(std::string username);
  void set_m_realname(std::string realname);
  void set_m_oper_flag(bool flag);
  void set_m_authorized(bool flag);
  void set_m_registered(bool flag);
};

#endif
