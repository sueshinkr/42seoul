#include "../include/socket.hpp"

SOCKET::SOCKET()
{
	if (_initSOCKET())
		this->_errcheck = ERR;
}

SOCKET::SOCKET(const CONFIG &config) : _config(config)
{
	if (_initSOCKET())
		this->_errcheck = ERR;
	if (_registerEpoll())
		this->_errcheck = ERR;
}

int	SOCKET::_initSOCKET(void)
{
	for (int i = 0; i < _config.getservNum(); i++)
	{
		int	servSock;

		if ((servSock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
		{
			perror("socket() error");
			return (ERR);
		}

		_setAddr(_config, i);

		if (bind(servSock, (struct sockaddr*)&getAddr(i), getAddrLen(i)) == -1)
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

		_server.push_back(servSock);
		std::cout << "init serv OK\n";
	}
	return (PASS);
}

int	SOCKET::_registerEpoll(void)
{
	if ((_epollFd = epoll_create(EPOLL_SIZE)) == -1)
		return (ERR);

	for (size_t i = 0; i < _server.size(); i++)
	{
		_events.events = EPOLLIN;
		_events.data.fd = _server[i].getfd();
		if (epoll_ctl(_epollFd, EPOLL_CTL_ADD, _server[i].getfd(), &_events) == -1)
			return (ERR);
	}
	return (PASS);
}

void				SOCKET::_setAddr(CONFIG conf, int servNum)
{
	struct sockaddr_in	addr;
	const char	*host;

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	host = conf.getHost(servNum).c_str();
	std::cout << "host : " << conf.getHost(servNum) << std::endl;
	addr.sin_addr.s_addr = inet_addr(strcmp(host, "localhost") == 0 ? "127.0.0.1" : host);
	addr.sin_port = htons(conf.getPort(servNum));

	this->_addr.push_back(addr);
	this->_addrLen.push_back(sizeof(addr));
}

void				SOCKET::_setNonBlock(int servSock)
{
	int flag = fcntl(servSock, F_GETFL, 0);
	fcntl(servSock, F_SETFL, flag | O_NONBLOCK);
}

int					SOCKET::findServerFd(int fd) const
{
	for (size_t i = 0; i < _server.size(); i++)
	{
		if (fd == _server[i].getfd())
			return (fd);
	}
	
	return (0);
}

/*---------------------------
		get_function
----------------------------*/

const sockaddr_in &	SOCKET::getAddr(int num) const
{
	return (_addr[num]);
}

const socklen_t &	SOCKET::getAddrLen(int num) const
{
	return (_addrLen[num]);
}

int					SOCKET::getEpollFd(void) const
{
	return (_epollFd);
}
