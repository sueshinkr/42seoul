#include "../include/client.hpp"

CLIENT::CLIENT()
{
}

CLIENT::CLIENT(int fd, int epollFd) : _fd(fd), _epollFd(epollFd)
{
}

int		CLIENT::recvMessage(void)
{
	std::cout << "Client " << getFd() << " request\n\n";

	char buf[10000];
	memset(buf, 0, sizeof(buf));

	ssize_t	recvLen;

	if ((recvLen = recv(getFd(), buf, 101, 0)) < 1)
	{
		std::cout << "::recvLen : " << recvLen << std::endl;
		std::cout << buf << std::endl;
		epoll_ctl(getEpollFd(), EPOLL_CTL_DEL, getFd(), NULL);
		close(getFd());
		return (ERR);
	}
	else
	{
		std::cout << "recvLen : " << recvLen << std::endl;
		std::cout << buf << std::endl;

		addMessage(buf);

		if (getMessage().find("\r\n") != std::string::npos)
		{
			std::cout << "==============recv End===============\n";
			std::cout << getMessage() << std::endl;
			std::cout << "==============Finish===============\n";

			epoll_ctl(getEpollFd(), EPOLL_CTL_DEL, getFd(), NULL);
			close(getFd());
		}
	}
	return (PASS);
}

void		CLIENT::addMessage(char *buf)
{
	_message += buf;
}

/*---------------------------
		get_function
----------------------------*/

int         CLIENT::getFd(void) const
{
    return (_fd);
}

int			CLIENT::getEpollFd(void) const
{
	return (_epollFd);
}

std::string	CLIENT::getMessage(void) const
{
	return (_message);
}
