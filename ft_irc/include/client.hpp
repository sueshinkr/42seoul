#ifndef CLIENT_HPP
# define CLIENT_HPP

//#include "../include/server.hpp"
#include <string>
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


class CLIENT
{
	private:
		int							_fd;
		int							_epollFd;
        std::string					_message;

	public:
		CLIENT();
		CLIENT(int fd, int epollFd);
		//CLIENT	&operator=(const CLIENT &client);

		int			recvMessage(void);
		void		addMessage(char *buf);

		int			getFd(void) const;
		int			getEpollFd(void) const;
		std::string	getMessage(void) const;
};

#endif
