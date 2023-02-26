#include "client.hpp"

CLIENT::CLIENT() : _request("")
{
}

CLIENT::CLIENT(int fd) : _fd(fd), _request("")
{
}

void CLIENT::addrequest(char *buf)
{
    _request += buf;
}

/*---------------------------
		get_function
----------------------------*/

int         CLIENT::getfd(void) const
{
    return (_fd);
}

std::string CLIENT::getrequest(void) const
{
    return (_request);
}
