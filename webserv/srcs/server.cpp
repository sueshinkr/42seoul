#include "server.hpp"

SERVER::SERVER()
{
}

SERVER::SERVER(int fd) : _fd(fd)
{
}

/*---------------------------
		get_function
----------------------------*/

int	SERVER::getFd(void) const
{
	return (_fd);
}


