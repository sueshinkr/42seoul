#ifndef SOCKET_HPP
# define SOCKET_HPP

#include "config.hpp"
#include <vector>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

class SOCKET
{
	private:
		std::vector<CONFIG>			_config;
		std::vector<sockaddr_in>	_addr;
		std::vector<socklen_t>		_addrLen;
		int							_epollFd;
		int							_errcheck;

		int							_initSOCKET(void);
		void						_setAddr(CONFIG conf);

	public:
		SOCKET();
		SOCKET(const SOCKET &socket);
		~SOCKET();

		SOCKET	&operator=(const SOCKET &socket);
		
		const sockaddr_in	getAddr(int num) const;
		const socklen_t		getAddrLen(int num) const;

};

#endif