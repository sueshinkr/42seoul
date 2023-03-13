#include "Client.hpp"

/*==============================
-----------generator----------s--
===============================*/

Client::Client() {}

Client::Client(int fd, int epollFd)
    : m_clnt_fd(fd),
      m_epoll_fd(epollFd),
      m_authorized(false),
      m_registered(false),
      m_oper_flag(false),
      m_invisible_flag(false) {}

/*==============================
--------private_function--------
===============================*/

int Client::sendMsg(std::string msg) {
  if (send(get_m_clnt_fd(), msg.c_str(), msg.length(), 0) == -1) return (ERR);
  std::cout << "send to client================================\n";
  std::cout << msg;
  std::cout << "==============================================\n";
  return (PASS);
}

/*==============================
----------get_function----------
===============================*/

int Client::get_m_clnt_fd(void) const { return (m_clnt_fd); }

int Client::get_m_epoll_fd(void) const { return (m_epoll_fd); }

bool Client::get_m_authorized() const { return (m_authorized); }

bool Client::get_m_registered() const { return (m_registered); }

bool Client::get_m_oper_flag(void) const { return (m_oper_flag); }

bool Client::get_m_invisible_flag(void) const { return (m_invisible_flag); }

std::string Client::get_m_hostname(void) const { return (m_hostname); }

std::string Client::get_m_nickname(void) const { return (m_nickname); }

std::string Client::get_m_username(void) const { return (m_username); }

std::string Client::get_m_realname(void) const { return (m_realname); }

std::vector<std::string> Client::get_m_channel(void) const {
  return (m_channel);
}

/*==============================
----------set_function----------
===============================*/

void Client::set_m_hostname(std::string hostname) { m_hostname = hostname; }

void Client::set_m_nickname(std::string nickname) { m_nickname = nickname; }

void Client::set_m_username(std::string username) { m_username = username; }

void Client::set_m_realname(std::string realname) { m_realname = realname; }

void Client::set_m_authorized(bool flag) { m_authorized = flag; }

void Client::set_m_registered(bool flag) { m_registered = flag; }

void Client::set_m_oper_flag(bool flag) { m_oper_flag = flag; }

void Client::set_m_invisible_flag(bool flag) { m_invisible_flag = flag; }
