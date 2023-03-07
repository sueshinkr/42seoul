#include "../include/client.hpp"

/*-----------------------------
                generator
------------------------------*/

CLIENT::CLIENT() {}

CLIENT::CLIENT(int fd, int epollFd, std::string hostname)
    : m_clnt_fd(fd), m_epoll_fd(epollFd), m_hostname(hostname) {
}

/*---------------------------
                get_function
----------------------------*/

int CLIENT::get_m_clnt_fd(void) const { return (m_clnt_fd); }

int CLIENT::get_m_epoll_fd(void) const { return (m_epoll_fd); }

std::string CLIENT::get_m_hostname(void) const { return (m_hostname); }

std::string CLIENT::get_m_nickname(void) const { return (m_nickname); }

std::string CLIENT::get_m_username(void) const { return (m_username); }

std::string CLIENT::get_m_realname(void) const { return (m_realname); }

/*---------------------------
                set_function
----------------------------*/

void CLIENT::set_m_nickname(std::string nickname) { m_nickname = nickname; }

void CLIENT::set_m_username(std::string username) { m_username = username; }

void CLIENT::set_m_realname(std::string realname) { m_realname = realname; }

void CLIENT::set_m_oper_flag(bool flag) { m_oper_flag = flag; }
