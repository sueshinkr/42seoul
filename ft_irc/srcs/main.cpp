
#include "../include/server.hpp"

int	waitEvent(SERVER & serv)
{
	struct epoll_event	events[EPOLL_SIZE];
	int					eventCnt;
	int					epollFd;

	epollFd = serv.getEpollFd();
	if ((eventCnt = epoll_wait(epollFd, events, EPOLL_SIZE, -1)) == -1)
	{
		perror("epoll_wait() error");
		return (ERR);
	}

	for (int i = 0; i < eventCnt; i++)
	{
		int eventFd = events[i].data.fd;

		if (eventFd == serv.getFd())
			serv.connectClient();
		else
			serv.getClient(eventFd).recvMessage();
	}
	return (PASS);
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		std::cout << "Usage : " << argv[0] << " <port> <password>\n";
		exit(1);
	}

	SERVER serv(atoi(argv[1]), argv[2]);

	while (waitEvent(serv) != ERR)
		;

	return (0);
}
