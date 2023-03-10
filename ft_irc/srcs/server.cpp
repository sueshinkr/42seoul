#include "../include/server.hpp"

/*-----------------------------
                generator
------------------------------*/

SERVER::SERVER() {}

SERVER::SERVER(int port, std::string password)
    : m_port(port), m_password(password) {
  if (initServer())
    this->m_err_check = ERR;
  if (registerEpoll())
    this->m_err_check = ERR;
}

/*-----------------------------
                private_function
------------------------------*/

int SERVER::initServer() {
  int serv_sock;

  if ((serv_sock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket() error");
    return (ERR);
  }

  memset(&m_addr, 0, sizeof(m_addr));
  m_addr.sin_family = AF_INET;
  m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  m_addr.sin_port = htons(get_m_port());

  if (bind(serv_sock, (struct sockaddr *)&m_addr, sizeof(m_addr)) ==
      -1) {
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

void SERVER::setNonBlock(int serv_sock) {
  int flag = fcntl(serv_sock, F_GETFL, 0);
  fcntl(serv_sock, F_SETFL, flag | O_NONBLOCK);
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
  m_fd_to_client[clntSock] = clnt;

  std::cout << "Connection Request : "
            << "socket " << clntSock << " - " << inet_ntoa(clntAddr.sin_addr)
            << " : " << ntohs(clntAddr.sin_port) << std::endl
            << std::endl;

  return (PASS);
}

int SERVER::recvData(int clnt_fd)
{
	std::cout << "Client " << clnt_fd << " request\n\n";

  char buf[1024];
  memset(buf, 0, sizeof(buf));

  ssize_t recvLen;

  if ((recvLen = recv(clnt_fd, buf, 1024, 0)) < 1) {
    std::cout << "recvError\n";
    epoll_ctl(get_m_epoll_fd(), EPOLL_CTL_DEL, clnt_fd, NULL);
    close(clnt_fd);
    return (ERR);
  } else {
    m_data += buf;
	splitCmd();
  }

    return (PASS);
}

int SERVER::splitCmd(){
  size_t prev = 0;
  size_t cur = m_data.find("\r\n");
  while (cur != std::string::npos) {
	m_cmd_line = m_data.substr(prev, cur - prev);
	std::cout << "cmd::::\n";
	std::cout << m_cmd_line << std::endl;
	
	//m_base_handler.set_cmd_line(m_cmd_line);
    //ExecuteCmd(m_base_handler);

	prev = cur + 2;
    cur = m_data.find("\r\n", prev);
  }
  m_data.clear();

  return (PASS);
}

//int ExecuteCmd()

/*---------------------------
                get_function
----------------------------*/

int SERVER::get_m_serv_fd(void) const { return (m_serv_fd); }

int SERVER::get_m_epoll_fd(void) const { return (m_epoll_fd); }

int SERVER::get_m_port() const { return (m_port); }

std::string SERVER::get_m_serv_name() const { return (m_serv_name); }

std::string SERVER::get_m_data() const { return (m_data); }

std::string SERVER::get_m_cmd_line() const { return (m_cmd_line); }

CLIENT &SERVER::get_m_client(int clnt) {
  return (m_fd_to_client.find(clnt)->second);
}

CLIENT &SERVER::get_m_client(std::string nickname) {
  return (m_nick_to_client.find(nickname)->second);
}

/*
Channel &SERVER::get_m_channel(std::string ch) {
  return (m_ch_to_channel.find(ch)->second);
}
*/
