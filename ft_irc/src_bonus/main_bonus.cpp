#include <signal.h>

#include "Server_bonus.hpp"
#include "Exit_bonus.hpp"

Server *g_serv;

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
    else if (event_fd == 0)
    {
      std::vector<std::string> rows = serv.get_m_bot().send_data();
      if (rows.size() > 0)
      {
        std::string channelName = rows[0];
        std::vector<std::string>::iterator iter = rows.begin();
        for (iter++; iter != rows.end(); iter++)
        {
          try {
            Channel &ch = serv.get_m_channel(channelName);
            ch.sendMsg(Response::privMsg("#🚇Bot", "#🚇Bot", "#🚇Bot", channelName, *iter));
          } catch (const std::exception &err) {
          }
        }
      }
      epoll_ctl(serv.get_m_epoll_fd(), EPOLL_CTL_DEL, 0, &serv.get_m_stdevents());
    }
    else {
      if (events[i].events & EPOLLIN)
        serv.recvData(event_fd);
      if (events[i].events & EPOLLOUT)
        serv.sendData(event_fd);
	}
  }
  return (PASS);
}

int main(int argc, char **argv) {
  std::set_new_handler(Exit::Handler);
  if (argc != 3) {
    std::cout << "Usage : " << argv[0] << " <port> <password>\n";
    exit(1);
  }

  for (size_t i = 0; i < strlen(argv[1]); i++) {
    if (isdigit(argv[1][i]) == 0) {
      std::cout << "Error : Port is not a positive number" << std::endl;
      exit(1);
    }
  }
  if (atoi(argv[1]) > 65535 || atoi(argv[1]) < 1) {
    std::cout << "Error : port range not valid: " << argv[1] << std::endl;
    exit(1);
  }
  signal(SIGINT, Exit::OnSignal);
  signal(SIGQUIT, Exit::OnSignal);
  Server *my_serv = new Server(atoi(argv[1]), argv[2]);
  Server &serv = *my_serv;
  g_serv = my_serv;
  if (serv.get_m_err_check() == -1) {
    delete my_serv;
    exit(1);
  }
  std::cout << "==============" << std::endl;
  std::cout << "Server Start!!" << std::endl;
  std::cout << "==============" << std::endl;
  while (waitEvent(serv) != ERR)
    ;

  delete my_serv;
  exit(1);
}
