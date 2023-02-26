#ifndef SOCKET_HPP
# define SOCKET_HPP

#include "config.hpp"
#include "server.hpp"
#include "client.hpp"

#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include <vector>

#define PASS		0
#define ERR			-1
#define BACKLOG		5
#define EPOLL_SIZE 50

class SOCKET
{
	private:
		CONFIG						_config;
		std::vector<SERVER>			_server;
		std::vector<CLIENT>			_client;
		std::vector<sockaddr_in>	_addr;
		std::vector<socklen_t>		_addrLen;
		int							_epollFd;
		int							_errcheck;
		struct epoll_event			_events;
		std::map<int, int>			_fdToClient;

		int							_initSOCKET(void);
		int							_registerEpoll(void);
		void						_setAddr(CONFIG conf, int servNum);
		void						_setNonBlock(int servSock);

	public:
		SOCKET();
		SOCKET(const CONFIG &config);
		//SOCKET(const SOCKET &socket);
		//~SOCKET();

		//SOCKET	&operator=(const SOCKET &socket);
		
		const sockaddr_in &			getAddr(int num) const;
		const socklen_t &			getAddrLen(int num) const;
		SERVER						getServer(int num) const;
		CLIENT &					getClient(int clnt);
		int							getEpollFd(void) const;
		int							findServerFd(int fd) const;
		void						addClient(int clnt);
		
};

#endif
