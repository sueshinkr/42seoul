#include "server.hpp"

SERVER::SERVER()
{
}

SERVER::SERVER(int fd) : _fd(fd)
{
}

int	SERVER::getfd(void) const
{
	return (_fd);
}
