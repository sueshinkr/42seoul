#ifndef SERVER_HPP
#define SERVER_HPP

#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>

#include <map>
#include <vector>

#include "../include/client.hpp"

#define PASS 0
#define ERR -1
#define BACKLOG 5
#define EPOLL_SIZE 50

class SERVER {
private:
  int m_serv_fd;
  int m_epoll_fd;
  int m_port;
  int m_err_check;

  std::string m_serv_name;
  std::string m_password;
  std::string m_data;
  std::string m_cmd_line;

  struct sockaddr_in m_addr;
  struct epoll_event m_events;
  std::map<int, CLIENT> m_fd_to_client;
  std::map<std::string, CLIENT> m_nick_to_client;
  //std::map<std::string, Channel> m_ch_to_channel;

  int initServer();
  int registerEpoll(void);
  void setNonBlock(int serv_fd);

public:
  SERVER();
  SERVER(int port, std::string password);

  int connectClient(void);
  int recvData(int clnt_fd);
  int splitCmd(void);

  int get_m_serv_fd(void) const;
  int get_m_epoll_fd(void) const;
  int get_m_port() const;
  std::string get_m_serv_name() const;
  std::string get_m_data() const;
  std::string get_m_cmd_line() const;
  CLIENT &get_m_client(int clnt);
  CLIENT &get_m_client(std::string nickname);
  //Channel &get_m_channel(std::string ch);


};

#endif
