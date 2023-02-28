#ifndef SERVER_HPP
# define SERVER_HPP

#include "../include/client.hpp"

#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <iostream>
#include <vector>
#include <map>

#define PASS		0
#define ERR			-1
#define BACKLOG		5
#define EPOLL_SIZE 50

class SERVER
{
	private:
		std::vector<CLIENT>			_client;
		int							_servFd;
		int							_epollFd;
		int							_errcheck;
		int							_port;
		std::string					_password;
		struct sockaddr_in			_addr;
		struct epoll_event			_events;
		std::map<int, int>			_clntFdtoClient;
		

		int							_initServer();
		void						_setAddr(void);
		void						_setNonBlock(int servSock);
		int							_registerEpoll(void);
		
	public:
		SERVER();
		SERVER(int port, std::string password);

		int							connectClient(void);

		int							getFd(void) const;
		int							getEpollFd(void) const;
		int							getPort() const;
		const sockaddr_in &			getAddr();
		CLIENT &					getClient(int clnt);

};

#endif
