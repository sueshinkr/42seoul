#ifndef SERVER_HPP
#define SERVER_HPP

#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

#include <map>
#include <vector>

#include "Channel.hpp"
#include "Client.hpp"
#include "Command.hpp"
#include "Response.hpp"

#define PASS 0
#define ERR -1
#define BACKLOG 5
#define EPOLL_SIZE 50

class Server {
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
  std::map<int, Client> m_fd_to_client;
  std::map<std::string, Client> m_nick_to_client;
  std::map<std::string, Channel> m_ch_to_channel;

  Pass pass;
  Nick nick;
  User user;
  Mode mode;
  Pong pong;
  Whois whois;
  Join join;
  Part part;
  Privmsg privmsg;
  Notice notice;
  Oper oper;
  Kick kick;
  Kill kill;
  Quit quit;

  int initServer(void);
  int registerEpoll(void);
  void handlerSetting(void);
  void setNonBlock(int serv_fd);
  void splitLine(int clnt_fd);
  int ExecuteCmd(BaseHandler &handler, std::string cmd, std::string cmd_line,
                 int clnt_fd);

 public:
  // Server();
  Server(int port, std::string password);

  int connectClient(void);
  int recvData(int clnt_fd);

  int get_m_serv_fd(void) const;
  int get_m_epoll_fd(void) const;
  int get_m_port(void) const;

  std::string get_m_serv_name(void) const;
  std::string get_m_password(void) const;
  std::string get_m_data(void) const;
  std::string get_m_cmd_line(void) const;
  struct epoll_event &get_m_events(void);
  Client &get_m_client(int clnt);
  Client &get_m_client(std::string nickname);
  Channel &get_m_channel(std::string ch);

  void set_m_data(std::string data);
  void set_m_fd_to_client(int clnt_fd, Client client);
  void set_m_nick_to_client(std::string nickname, Client client);
  void set_m_ch_to_channel(std::string ch, Channel channel);

  void del_m_fd_to_client(int clnt_fd);
  void del_m_nick_to_client(std::string nickname);
  void del_m_ch_to_channel(std::string ch);

};

#endif
