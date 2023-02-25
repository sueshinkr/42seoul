
#include "../include/socket.hpp"

std::string configName(int argc, char **argv)
{
	std::string confFile = "default.conf";

	if (argc >= 2)
		confFile = argv[1];
	return (confFile);
}

int	connectClient(int epollFd, int servSock)
{
	int					clntSock;
	struct sockaddr_in	clntAddr;
	socklen_t			clntAddrLen;
	struct epoll_event	event;
	char buf[10000];

	clntAddrLen = sizeof(clntAddr);
	if ((clntSock = accept(servSock, (sockaddr*)&clntAddr, &clntAddrLen)) == -1)	
		return (ERR);

	event.events = EPOLLIN;
	event.data.fd = clntSock;

	int flag = fcntl(clntSock, F_GETFL, 0);
	fcntl(clntSock, F_SETFL, flag | O_NONBLOCK);

	if (epoll_ctl(epollFd, EPOLL_CTL_ADD, clntSock, &event) == -1)
		return (ERR);

	while (recv(servSock, buf, 10000, 0) > 0)
		;
	std::cout << "buf : " << buf << std::endl;
	std::cout << "Connection Request : " << "socket " << clntSock << " - " << inet_ntoa(clntAddr.sin_addr) << " : " << ntohs(clntAddr.sin_port) << std::endl << std::endl;

	return (PASS);
}

int recvRequest(int clntSock)
{
	std::cout << "Client " << clntSock << " request\n\n";

	char buf[10000];
	memset(buf, 0, sizeof(buf));

	while (recv(clntSock, buf, 10000, 0) > 0)
		;

	std::cout << buf << std::endl;

	return (PASS);
}

int	waitEvent(SOCKET sock)
{
	struct epoll_event	events[EPOLL_SIZE];
	int					eventCnt;
	int					epollFd;

	epollFd = sock.getEpollFd();
	if ((eventCnt = epoll_wait(epollFd, events, EPOLL_SIZE, -1)) == -1)
	{
		perror("epoll_wait() error");
		return (ERR);
	}

	for (int i = 0; i < eventCnt; i++)
	{
		int fd = events[i].data.fd;
		std::cout << "event fd : " << fd << std::endl;
		if (sock.findServerFd(fd))
			connectClient(epollFd, fd);
		else
			recvRequest(fd);
	}
	return (PASS);
}

int main(int argc, char **argv)
{
	CONFIG config(configName(argc, argv));
	SOCKET sock(config);

	while (waitEvent(sock) != ERR)
		;

	return (0);
}
