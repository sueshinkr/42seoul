
#include "../include/socket.hpp"

std::string configName(int argc, char **argv)
{
	std::string confFile = "default.conf";

	if (argc >= 2)
		confFile = argv[1];
	return (confFile);
}

int main(int argc, char **argv)
{
	CONFIG config(configName(argc, argv));
	SOCKET sock(config);

	return (0);
}
