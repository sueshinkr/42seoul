#include "Server.hpp"

/*==============================
-----------generator------------
===============================*/

// Server::Server() {}

Server::Server(int port, std::string password)
    : m_port(port),
      m_password(password),
      pass(*this),
      nick(*this),
      user(*this),
      mode(*this),
      pong(*this),
      join(*this),
      whois(*this),
      part(*this),
      privmsg(*this),
      notice(*this),
      oper(*this),
      kick(*this),
      kill(*this),
      quit(*this) {
  if (initServer()) this->m_err_check = ERR;
  if (registerEpoll()) this->m_err_check = ERR;
  handlerSetting();
}

/*==============================
--------private_function--------
===============================*/

int Server::initServer() {
  int serv_sock;

  if ((serv_sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket() error");
    return (ERR);
  }

  memset(&m_addr, 0, sizeof(m_addr));
  m_addr.sin_family = AF_INET;
  m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  m_addr.sin_port = htons(get_m_port());

  if (bind(serv_sock, (struct sockaddr *)&m_addr, sizeof(m_addr)) == -1) {
    perror("bind() error");
    return (ERR);
  }

  if (listen(serv_sock, BACKLOG) < 0) {
    perror("listen() error");
    return (ERR);
  }

  setNonBlock(serv_sock);

  m_serv_fd = serv_sock;

  char temp[256];
  gethostname(temp, 256);
  m_serv_name = temp;
  Response::set_m_serv_name(m_serv_name);

  return (PASS);
}

int Server::registerEpoll(void) {
  if ((m_epoll_fd = epoll_create(EPOLL_SIZE)) == -1) return (ERR);

  m_events.events = EPOLLIN;
  m_events.data.fd = get_m_serv_fd();
  if (epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, get_m_serv_fd(), &m_events) == -1)
    return (ERR);

  return (PASS);
}

void Server::handlerSetting(void) {
  pass.setNext(&nick)
      ->setNext(&user)
      ->setNext(&mode)
      ->setNext(&pong)
      ->setNext(&whois)
      ->setNext(&join)
      ->setNext(&part)
      ->setNext(&privmsg)
      ->setNext(&notice)
      ->setNext(&oper)
      ->setNext(&kick)
      ->setNext(&kill)
      ->setNext(&quit);
}

void Server::setNonBlock(int serv_sock) {
  int flag = fcntl(serv_sock, F_GETFL, 0);
  fcntl(serv_sock, F_SETFL, flag | O_NONBLOCK);
}

void Server::splitLine(int clnt_fd) {
  size_t prev = 0;
  size_t cur = m_data.find("\r\n");
  while (cur != std::string::npos) {
    m_cmd_line = m_data.substr(prev, cur - prev);

    size_t line_cur = m_cmd_line.find(" ");
    std::string cmd = m_cmd_line.substr(0, line_cur);
    std::string request = m_cmd_line.substr(line_cur + 1, -1);
    std::cout << "cmd : " << cmd << std::endl;
    std::cout << "request : " << request << std::endl;
    if (ExecuteCmd(pass, cmd, request, clnt_fd) == -1) break;

    prev = cur + 2;
    cur = m_data.find("\r\n", prev);
  }
  m_data.clear();
}

int Server::ExecuteCmd(BaseHandler &handler, std::string cmd,
                       std::string request, int clnt_fd) {
  if (handler.handle(cmd, request, get_m_client(clnt_fd))) return (PASS);
  return (ERR);
}

/*==============================
---------public_function--------
===============================*/

int Server::connectClient() {
  int clnt_sock;
  struct sockaddr_in clnt_addr;
  socklen_t clnt_addr_len;
  struct epoll_event event;

  clnt_addr_len = sizeof(clnt_addr);
  if ((clnt_sock = accept(get_m_serv_fd(), (sockaddr *)&clnt_addr,
                          &clnt_addr_len)) == -1)
    return (ERR);

  event.events = EPOLLIN;
  event.data.fd = clnt_sock;

  setNonBlock(clnt_sock);

  if (epoll_ctl(get_m_epoll_fd(), EPOLL_CTL_ADD, clnt_sock, &event) == -1)
    return (ERR);

  Client clnt(clnt_sock, get_m_epoll_fd());
  m_fd_to_client[clnt_sock] = clnt;

  std::cout << "Connection Request : "
            << "socket " << clnt_sock << " - " << inet_ntoa(clnt_addr.sin_addr)
            << " : " << ntohs(clnt_addr.sin_port) << std::endl
            << std::endl;

  return (PASS);
}

int Server::recvData(int clnt_fd) {
  char buf[1024];
  memset(buf, 0, sizeof(buf));

  ssize_t recv_len;

  if ((recv_len = recv(clnt_fd, buf, 1024, 0)) < 1) {
    std::cout << "recvError\n";
    epoll_ctl(get_m_epoll_fd(), EPOLL_CTL_DEL, clnt_fd, NULL);
    close(clnt_fd);
    return (ERR);
  } else {
    set_m_data(static_cast<std::string>(buf));
    splitLine(clnt_fd);
  }

  return (PASS);
}

/*==============================
----------get_function----------
===============================*/

int Server::get_m_serv_fd(void) const { return (m_serv_fd); }

int Server::get_m_epoll_fd(void) const { return (m_epoll_fd); }

int Server::get_m_port() const { return (m_port); }

std::string Server::get_m_serv_name() const { return (m_serv_name); }

std::string Server::get_m_password() const { return (m_password); }

std::string Server::get_m_data() const { return (m_data); }

std::string Server::get_m_cmd_line() const { return (m_cmd_line); }

struct epoll_event &Server::get_m_events() {
  return (m_events);
}

Client &Server::get_m_client(int clnt_fd) {
  std::map<int, Client>::iterator client_iter = m_fd_to_client.find(clnt_fd);

  if (client_iter == m_fd_to_client.end()) throw std::out_of_range("");

  return (client_iter->second);
}

Client &Server::get_m_client(std::string nickname) {
  std::map<std::string, Client>::iterator client_iter =
      m_nick_to_client.find(nickname);

  if (client_iter != m_nick_to_client.end()) throw std::exception();

  return (client_iter->second);
}

Channel &Server::get_m_channel(std::string ch) {
  std::map<std::string, Channel>::iterator channel_iter =
      m_ch_to_channel.find(ch);

  if (channel_iter == m_ch_to_channel.end()) throw std::out_of_range("");

  return (channel_iter->second);
}

/*==============================
----------set_function----------
===============================*/

void Server::set_m_data(std::string data) { m_data = data; }

void Server::set_m_fd_to_client(int clnt_fd, Client client) {
  m_fd_to_client[clnt_fd] = client;
}

void Server::set_m_nick_to_client(std::string nickname, Client client) {
  m_nick_to_client[nickname] = client;
}

void Server::set_m_ch_to_channel(std::string ch, Channel channel) {
  m_ch_to_channel[ch] = channel;
}

void Server::del_m_fd_to_client(int clnt_fd) { m_fd_to_client.erase(clnt_fd); }

void Server::del_m_nick_to_client(std::string nickname) {
  m_nick_to_client.erase(nickname);
}

void Server::del_m_ch_to_channel(std::string ch) { m_ch_to_channel.erase(ch); }