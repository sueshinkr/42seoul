#include "Client.hpp"
#include "Exit.hpp"

/*==============================
-----------generator------------
===============================*/

Client::Client() {}

Client::Client(int fd, int epollFd)
    : m_clnt_fd(fd), m_epoll_fd(epollFd), m_authorized(false),
      m_registered(false), m_oper_flag(false), m_invisible_flag(false) {
  memset(&m_events, 0, sizeof(m_events));
}

/*==============================
--------private_function--------
===============================*/

void Client::sendMsg(std::string msg) {

  m_buf += msg;
  m_events.events = EPOLLIN | EPOLLOUT;

  if (epoll_ctl(m_epoll_fd, EPOLL_CTL_MOD, m_clnt_fd, &m_events) == -1)
  {
	 if (errno == ENOMEM)
      Exit::Handler();
  }
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


std::string Client::get_m_data(void) const { return (m_data); }

std::string Client::get_m_buf(void) const { return (m_buf); }

std::string Client::get_m_hostname(void) const { return (m_hostname); }

std::string Client::get_m_nickname(void) const { return (m_nickname); }

std::string Client::get_m_username(void) const { return (m_username); }

std::string Client::get_m_realname(void) const { return (m_realname); }

struct epoll_event &Client::get_m_events() {
  return (m_events);
}

std::vector<std::string> Client::get_m_channel(void) const {
  return (m_channel);
}

/*==============================
----------set_function----------
===============================*/

void Client::set_m_data(std::string data) { m_data += data; }

void Client::set_m_buf(size_t cur) { m_buf = m_buf.substr(cur, std::string::npos); }

void Client::set_m_hostname(std::string hostname) { m_hostname = hostname; }

void Client::set_m_nickname(std::string nickname) { m_nickname = nickname; }

void Client::set_m_username(std::string username) { m_username = username; }

void Client::set_m_realname(std::string realname) { m_realname = realname; }

void Client::set_m_channel(std::string channel_name) {
  m_channel.push_back(channel_name);
}

void Client::set_m_authorized(bool flag) { m_authorized = flag; }

void Client::set_m_registered(bool flag) { m_registered = flag; }

void Client::set_m_oper_flag(bool flag) { m_oper_flag = flag; }

void Client::set_m_invisible_flag(bool flag) { m_invisible_flag = flag; }

/*==============================
----------del_function----------
===============================*/

void Client::del_m_data() { m_data.clear(); }

void Client::del_m_buf() { m_buf.clear(); }

void Client::del_m_channel(std::string channel_name) {
  for (std::vector<std::string>::iterator iter = m_channel.begin();
       iter != m_channel.end(); iter++) {
    if ((*iter) == channel_name) {
      m_channel.erase(iter);
      break;
    }
  }
}
