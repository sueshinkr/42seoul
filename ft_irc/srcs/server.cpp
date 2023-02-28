#include "../include/server.hpp"

/*-----------------------------
		private_function
------------------------------*/

SERVER::SERVER()
{
}

SERVER::SERVER(int port, std::string password) : _port(port), _password(password)
{
	if (_initServer())
		this->_errcheck = ERR;
	if (_registerEpoll())
		this->_errcheck = ERR;
}

int		SERVER::_initServer()
{
	int	servSock;

	if ((servSock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket() error");
		return (ERR);
	}

	_setAddr();

	if (bind(servSock, (struct sockaddr*)&getAddr(), sizeof(getAddr())) == -1)
	{
		perror("bind() error");
		return (ERR);
	}

	if (listen(servSock, BACKLOG) < 0)
	{
		perror("listen() error");
		return (ERR);
	}

	_setNonBlock(servSock);

	_servFd = servSock;

	return (PASS);
}

int		SERVER::_registerEpoll(void)
{
	if ((_epollFd = epoll_create(EPOLL_SIZE)) == -1)
		return (ERR);

	_events.events = EPOLLIN;
	_events.data.fd = getFd();
	if (epoll_ctl(_epollFd, EPOLL_CTL_ADD, getFd(), &_events) == -1)
		return (ERR);

	return (PASS);
}

void				SERVER::_setAddr(void)
{
	memset(&_addr, 0, sizeof(_addr));
	_addr.sin_family = AF_INET;
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	_addr.sin_port = htons(getPort());
}

void	SERVER::_setNonBlock(int servSock)
{
	int flag = fcntl(servSock, F_GETFL, 0);
	fcntl(servSock, F_SETFL, flag | O_NONBLOCK);
}

/*-----------------------------
		public_function
------------------------------*/

int					SERVER::connectClient()
{
	int					clntSock;
	struct sockaddr_in	clntAddr;
	socklen_t			clntAddrLen;
	struct epoll_event	event;

	clntAddrLen = sizeof(clntAddr);
	if ((clntSock = accept(getFd(), (sockaddr*)&clntAddr, &clntAddrLen)) == -1)	
		return (ERR);

	event.events = EPOLLIN;
	event.data.fd = clntSock;

	_setNonBlock(clntSock);

	if (epoll_ctl(getEpollFd(), EPOLL_CTL_ADD, clntSock, &event) == -1)
		return (ERR);

	CLIENT	clnt(clntSock, getEpollFd());
	_clntFdtoClient[clntSock] = _client.size();
	_client.push_back(clnt);

	std::cout << "Connection Request : " << "socket " << clntSock << " - " << inet_ntoa(clntAddr.sin_addr) << " : " << ntohs(clntAddr.sin_port) << std::endl << std::endl;

	return (PASS);
}

/*---------------------------
		get_function
----------------------------*/

int					SERVER::getFd(void) const
{
	return (_servFd);
}

int					SERVER::getEpollFd(void) const
{
	return (_epollFd);
}

int					SERVER::getPort() const
{
	return (_port);
}

const sockaddr_in &	SERVER::getAddr()
{
	return (_addr);
}

CLIENT &			SERVER::getClient(int clnt)
{
	return (_client[_clntFdtoClient.find(clnt)->second]);
}


