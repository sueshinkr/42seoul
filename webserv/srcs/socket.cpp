#include "socket.hpp"
#define PASS	0
#define ERR		-1
#define BACKLOG	5
SOCKET::SOCKET()
{
	if (_initSOCKET())
		this->_errcheck = ERR;
}

int	SOCKET::_initSOCKET(void)
{
	int	serv_sock;

	for (size_t i = 0; i < _config.size(); i++)
	{
		if ((serv_sock =socket(PF_INET, SOCK_STREAM, 0)) < 0)
		{
			perror("socket() error");
			return (ERR);
		}

		_setAddr(_config[i]);

		if (bind(serv_sock, (sockaddr*)&getAddr(i), sizeof(getAddrLen(i)) == -1))
		{
			perror("bind() error");
			return (ERR);
		}

		if (listen(serv_sock, BACKLOG) < 0)
		{
			perror("listen() error");
			return (ERR);
		}
	}
	return (PASS);
}

const sockaddr_in SOCKET::getAddr(int num) const
{
	return (_addr[num]);
}

const socklen_t SOCKET::getAddrLen(int num) const
{
	return (_addrLen[num]);
}

void			SOCKET::_setAddr(CONFIG conf)
{
	struct sockaddr_in	addr;

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = conf.getHost().c_str();
	addr.sin_port = conf.getPort();

	this->_addr.push_back(addr);
	this->_addrLen.push_back(sizeof(addr));
}
