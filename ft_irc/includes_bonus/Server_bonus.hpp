#ifndef SERVER_HPP
#define SERVER_HPP

#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

#include <cerrno>
#include <map>
#include <vector>

#include "Channel_bonus.hpp"
#include "Client_bonus.hpp"
#include "Command_bonus.hpp"
#include "Response_bonus.hpp"

#include "StationBot_bonus.hpp"
#include "Util_bonus.hpp"


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
  struct epoll_event m_stdinevents;
  std::map<int, Client *> m_fd_to_client;
  std::map<std::string, Client *> m_nick_to_client;
  std::map<std::string, Channel *> m_ch_to_channel;

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

  StationBot b;

  int initServer(void);
  int registerEpoll(void);
  void handlerSetting(void);
  void setNonBlock(int serv_fd);
  void splitLine(int clnt_fd);
  int ExecuteCmd(BaseHandler &handler, std::string cmd, std::string cmd_line,
                 int clnt_fd);

 public:
  ~Server();
  Server(int port, std::string password);

  int connectClient(void);
  int recvData(int clnt_fd);
  int sendData(int clnt_fd);
  void disconnectClient(int clnt_fd);
  void sendBot(std::string channelName, std::string station);

  int get_m_serv_fd(void) const;
  int get_m_epoll_fd(void) const;
  int get_m_port(void) const;
  int get_m_err_check(void) const;

  std::string get_m_serv_name(void) const;
  std::string get_m_password(void) const;
  std::string get_m_data(void) const;
  std::string get_m_cmd_line(void) const;
  struct epoll_event &get_m_events(void);
  struct epoll_event &get_m_stdevents(void);
  Client &get_m_client(int clnt);
  Client &get_m_client(std::string nickname);
  Channel &get_m_channel(std::string ch);
  StationBot &get_m_bot();

  void set_m_data(std::string data);
  void set_m_fd_to_client(int clnt_fd, Client *client);
  void set_m_nick_to_client(std::string nickname, Client *client);
  void set_m_ch_to_channel(std::string ch, Channel *channel);

  void del_m_fd_to_client(int clnt_fd);
  void del_m_nick_to_client(std::string nickname);
  void del_m_ch_to_channel(std::string ch);
};

#endif
