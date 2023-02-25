#ifndef SERVER_HPP
# define SERVER_HPP

class SERVER
{
	private:
		int	_fd;

	public:
		SERVER();
		SERVER(int fd);

		int	getfd(void) const;
};

#endif
