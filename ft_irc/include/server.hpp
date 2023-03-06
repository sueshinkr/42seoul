#ifndef SERVER_HPP
#define SERVER_HPP

#include <arpa/inet.h>
#include <fcntl.h>

#include <map>
#include <vector>

#include "../include/client.hpp"

#define PASS 0
#define ERR -1
#define BACKLOG 5
#define EPOLL_SIZE 50

class SERVER {
 private:
  std::vector<CLIENT> m_client;
  int m_serv_fd;
  int m_epoll_fd;
  int m_err_check;
  int m_port;
  std::string m_password;
  struct sockaddr_in m_addr;
  struct epoll_event m_events;
  std::map<int, int> m_clntFdtoClient;

  int initServer();

  void setNonBlock(int servSock);
  int registerEpoll(void);

 public:
  SERVER();
  SERVER(int port, std::string password);

  int connectClient(void);

  int get_m_serv_fd(void) const;
  int get_m_epoll_fd(void) const;
  int get_m_port() const;
  const sockaddr_in &get_m_addr();
  CLIENT &get_m_client(int clnt);

  void set_m_addr(void);
};

#endif
