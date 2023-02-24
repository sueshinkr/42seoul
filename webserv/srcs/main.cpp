#ifndef SOCKET_HPP
# define SOCKET_HPP
#include <vector>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>

class SOCKET
{
	private:
		std::vector<CONFIG>			_config;
		std::vector<sockaddr_in>	_addr;
		std::vector<socklen_t>		_addrlen;
		int							_epollfd;

		int							_initSOCKET(void);

	public:
		SOCKET();
		SOCKET(const SOCKET &socket);
		~SOCKET();

		SOCKET	&operator=(const SOCKET &socket);


};

#endif
