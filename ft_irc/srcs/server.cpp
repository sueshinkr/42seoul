#include "../include/server.hpp"

/*-----------------------------
                private_function
------------------------------*/

SERVER::SERVER() {}

SERVER::SERVER(int port, std::string password)
    : m_port(port), m_password(password) {
  if (initServer())
    this->m_err_check = ERR;
  if (registerEpoll())
    this->m_err_check = ERR;
}

int SERVER::initServer() {
  int servSock;

  if ((servSock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket() error");
    return (ERR);
  }

  set_m_addr();

  if (bind(servSock, (struct sockaddr *)&get_m_addr(), sizeof(get_m_addr())) ==
      -1) {
    perror("bind() error");
    return (ERR);
  }

  if (listen(servSock, BACKLOG) < 0) {
    perror("listen() error");
    return (ERR);
  }

  setNonBlock(servSock);

  m_serv_fd = servSock;

  return (PASS);
}

int SERVER::registerEpoll(void) {
  if ((m_epoll_fd = epoll_create(EPOLL_SIZE)) == -1)
    return (ERR);

  m_events.events = EPOLLIN;
  m_events.data.fd = get_m_serv_fd();
  if (epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, get_m_serv_fd(), &m_events) == -1)
    return (ERR);

  return (PASS);
}

void SERVER::set_m_addr(void) {
  memset(&m_addr, 0, sizeof(m_addr));
  m_addr.sin_family = AF_INET;
  m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  m_addr.sin_port = htons(get_m_port());
}

void SERVER::setNonBlock(int servSock) {
  int flag = fcntl(servSock, F_GETFL, 0);
  fcntl(servSock, F_SETFL, flag | O_NONBLOCK);
}

/*-----------------------------
                public_function
------------------------------*/

int SERVER::connectClient() {
  int clntSock;
  struct sockaddr_in clntAddr;
  socklen_t clntAddrLen;
  struct epoll_event event;

  clntAddrLen = sizeof(clntAddr);
  if ((clntSock =
           accept(get_m_serv_fd(), (sockaddr *)&clntAddr, &clntAddrLen)) == -1)
    return (ERR);

  event.events = EPOLLIN;
  event.data.fd = clntSock;

  setNonBlock(clntSock);

  if (epoll_ctl(get_m_epoll_fd(), EPOLL_CTL_ADD, clntSock, &event) == -1)
    return (ERR);

  CLIENT clnt(clntSock, get_m_epoll_fd());
  m_clntFdtoClient[clntSock] = m_client.size();
  m_client.push_back(clnt);

  std::cout << "Connection Request : "
            << "socket " << clntSock << " - " << inet_ntoa(clntAddr.sin_addr)
            << " : " << ntohs(clntAddr.sin_port) << std::endl
            << std::endl;

  return (PASS);
}

/*---------------------------
                get_function
----------------------------*/

int SERVER::get_m_serv_fd(void) const { return (m_serv_fd); }

int SERVER::get_m_epoll_fd(void) const { return (m_epoll_fd); }

int SERVER::get_m_port() const { return (m_port); }

const sockaddr_in &SERVER::get_m_addr() { return (m_addr); }

CLIENT &SERVER::get_m_client(int clnt) {
  return (m_client[m_clntFdtoClient.find(clnt)->second]);
}
