#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "string"

class CLIENT
{
	private:
		int							_fd;
        std::string					_request;

	public:
		CLIENT();
		CLIENT(int fd);
		//CLIENT	&operator=(const CLIENT &client);

		int			getfd(void) const;
		std::string	getrequest(void) const;
		void		addrequest(char *buf);
};

#endif
