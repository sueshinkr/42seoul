#include "Server.hpp"

std::string Response::m_serv_name = "";

int waitEvent(Server &serv) {
  struct epoll_event events[EPOLL_SIZE];
  int event_cnt;
  int epoll_fd;

  epoll_fd = serv.get_m_epoll_fd();
  if ((event_cnt = epoll_wait(epoll_fd, events, EPOLL_SIZE, -1)) == -1) {
    perror("epoll_wait() error");
    return (ERR);
  }

  for (int i = 0; i < event_cnt; i++) {
    int event_fd = events[i].data.fd;

    if (event_fd == serv.get_m_serv_fd())
      serv.connectClient();
    else
      serv.recvData(event_fd);
  }
  return (PASS);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cout << "Usage : " << argv[0] << " <port> <password>\n";
    exit(1);
  }

  Server serv(atoi(argv[1]), argv[2]);

  while (waitEvent(serv) != ERR)
    ;

  return (0);
}
