#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <string>

#define PASS 0
#define ERR -1
#define BACKLOG 5
#define EPOLL_SIZE 50

class CLIENT {
 private:
  int m_clnt_fd;
  int m_epoll_fd;
  std::string m_message;

 public:
  CLIENT();
  CLIENT(int fd, int epollFd);

  int recvMessage(void);
  void cleanMessage(void);
  void addMessage(char *buf);

  int get_m_clnt_fd(void) const;
  int get_m_epoll_fd(void) const;
  std::string get_m_message(void) const;
};

#endif
