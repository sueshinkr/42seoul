#include "Client.hpp"

/*==============================
-----------generator------------
===============================*/

//Client::Client() {} 

Client::Client(Server &server) : m_server(server)
{
	std::cout << server.get_m_port() << std::endl;
}

Client::Client(int fd, int epollFd) : m_clnt_fd(fd), m_epoll_fd(epollFd) {}

/*==============================
--------private_function--------
===============================*/

int Client::sendMsg(std::string msg) {
  if (send(get_m_clnt_fd(), msg.c_str(), sizeof(msg), 0) == -1) return (ERR);
  return (PASS);
}

/*==============================
----------get_function----------
===============================*/

int Client::get_m_clnt_fd(void) const { return (m_clnt_fd); }

int Client::get_m_epoll_fd(void) const { return (m_epoll_fd); }

std::string Client::get_m_hostname(void) const { return (m_hostname); }

std::string Client::get_m_nickname(void) const { return (m_nickname); }

std::string Client::get_m_username(void) const { return (m_username); }

std::string Client::get_m_realname(void) const { return (m_realname); }

/*==============================
----------set_function----------
===============================*/

void Client::set_m_hostname(std::string hostname) { m_hostname = hostname; }

void Client::set_m_nickname(std::string nickname) { m_nickname = nickname; }

void Client::set_m_username(std::string username) { m_username = username; }

void Client::set_m_realname(std::string realname) { m_realname = realname; }

void Client::set_m_oper_flag(bool flag) { m_oper_flag = flag; }
