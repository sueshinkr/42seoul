
#include "../include/socket.hpp"

std::string configName(int argc, char **argv)
{
	std::string confFile = "default.conf";

	if (argc >= 2)
		confFile = argv[1];
	return (confFile);
}

int	connectClient(SOCKET & sock, int servSock)
{
	int					clntSock;
	struct sockaddr_in	clntAddr;
	socklen_t			clntAddrLen;
	struct epoll_event	event;

	

	clntAddrLen = sizeof(clntAddr);
	if ((clntSock = accept(servSock, (sockaddr*)&clntAddr, &clntAddrLen)) == -1)	
		return (ERR);

	event.events = EPOLLIN;
	event.data.fd = clntSock;

	int flag = fcntl(clntSock, F_GETFL, 0);
	fcntl(clntSock, F_SETFL, flag | O_NONBLOCK);

	if (epoll_ctl(sock.getEpollFd(), EPOLL_CTL_ADD, clntSock, &event) == -1)
		return (ERR);

	sock.addClient(clntSock);

	std::cout << "Connection Request : " << "socket " << clntSock << " - " << inet_ntoa(clntAddr.sin_addr) << " : " << ntohs(clntAddr.sin_port) << std::endl << std::endl;

	return (PASS);
}

int recvRequest(SOCKET & sock, int clntSock)
{
	std::cout << "Client " << clntSock << " request\n\n";

	CLIENT *clnt = &(sock.getClient(clntSock));

	char buf[10000];
	memset(buf, 0, sizeof(buf));

	ssize_t	recvLen;

	if ((recvLen = recv(clntSock, buf, 101, 0)) < 1)
	{
		std::cout << "recvLen : " << recvLen << std::endl;
		std::cout << "---------end---------\n";


		std::string	protocol = "HTTP/1.0 200 OK\r\n";
		std::string	server = "Server: simple web server\r\n";
		std::string	cnt_len = "Content-length: 2048\r\n";
		std::string	cnt_type = "Content-type: text/html\r\n\r\n";
		std::string body = "hello, world!\n";

		std::string to_send = protocol + server + cnt_len + cnt_type + body;

		send(clntSock, to_send.c_str(), to_send.size(), 0);

		epoll_ctl(sock.getEpollFd(), EPOLL_CTL_DEL, clntSock, NULL);
		close(clntSock);
		return (PASS);
	}
	else
	{
		std::cout << "recvLen : " << recvLen << std::endl;
		std::cout << buf << std::endl;

		clnt->addrequest(buf);

		if (clnt->getrequest().find("\r\n\r\n") != std::string::npos)
		{
			std::cout << "==============recv End===============\n";
			std::cout << clnt->getrequest() << std::endl;

			std::string	protocol = "HTTP/1.0 200 OK\r\n";
			std::string	server = "Server: simple web server\r\n";
			std::string	cnt_len = "Content-length: 2048\r\n";
			std::string	cnt_type = "Content-type: text/html\r\n\r\n";
			std::string body = "hello, world!\n";

			std::string to_send = protocol + server + cnt_len + cnt_type + body;

			send(clntSock, to_send.c_str(), to_send.size(), 0);

			std::cout << "==============Finish===============\n";

			epoll_ctl(sock.getEpollFd(), EPOLL_CTL_DEL, clntSock, NULL);
			close(clntSock);
		}
	}
	return (PASS);
}

int	waitEvent(SOCKET & sock)
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
		std::cout << "event fd : " << fd << " : " << events[i].events << std::endl;

		int servNum;
		if ((servNum = sock.findServerFd(fd)) >= 0)
			connectClient(sock, fd);
		else
			recvRequest(sock, fd);
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
