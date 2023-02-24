#include "../include/socket.hpp"

#define PASS	0
#define ERR		-1
#define BACKLOG	5

SOCKET::SOCKET()
{
	if (_initSOCKET())
		this->_errcheck = ERR;
}

SOCKET::SOCKET(const CONFIG &config) : _config(config)
{
	if (_initSOCKET())
		this->_errcheck = ERR;
}

int	SOCKET::_initSOCKET(void)
{
	int	servSock;

	for (int i = 0; i < _config.getservNum(); i++)
	{
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
	}
	std::cout << "init serv OK\n";
	return (PASS);
}

const sockaddr_in & SOCKET::getAddr(int num) const
{
	return (_addr[num]);
}

const socklen_t & SOCKET::getAddrLen(int num) const
{
	return (_addrLen[num]);
}

void			SOCKET::_setAddr(CONFIG conf, int servNum)
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
