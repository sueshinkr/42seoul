#include "../include/client.hpp"

CLIENT::CLIENT() {}

CLIENT::CLIENT(int fd, int epollFd) : m_clnt_fd(fd), m_epoll_fd(epollFd) {}

int CLIENT::recvMessage(void) {
  std::cout << "Client " << get_m_clnt_fd() << " request\n\n";

  char buf[1024];
  memset(buf, 0, sizeof(buf));

  ssize_t recvLen;

  if ((recvLen = recv(get_m_clnt_fd(), buf, 1024, 0)) < 1) {
    std::cout << "recvError\n";
    epoll_ctl(get_m_epoll_fd(), EPOLL_CTL_DEL, get_m_clnt_fd(), NULL);
    close(get_m_clnt_fd());
    return (ERR);
  } else {
    cleanMessage();
    addMessage(buf);

    std::cout << "==============recv End===============\n";
    std::cout << get_m_message() << std::endl;
    std::cout << "==============Finish===============\n";

    // 한줄씩 나누기
    size_t prev = 0;
    size_t cur = m_message.find("\r\n");
    while (cur != std::string::npos) {
      std::string cmd_line = m_message.substr(prev, cur - prev);
	  std::cout << "cmd::::\n";
	  std::cout << cmd_line << std::endl;
      // handler(cmd_line);
      prev = cur + 2;
      cur = m_message.find("\r\n", prev);
    }
    return (PASS);
  }
}

void CLIENT::cleanMessage(void) { m_message.clear(); }

void CLIENT::addMessage(char *buf) { m_message += buf; }

/*---------------------------
                get_function
----------------------------*/

int CLIENT::get_m_clnt_fd(void) const { return (m_clnt_fd); }

int CLIENT::get_m_epoll_fd(void) const { return (m_epoll_fd); }

std::string CLIENT::get_m_message(void) const { return (m_message); }
