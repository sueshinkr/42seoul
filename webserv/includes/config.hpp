#ifndef CONFIG_HPP
# define CONFIG_HPP
#include <string>
#include <vector>
#include <fstream>
#include <map>

class CONFIG
{
	private:
		enum 							METHODS_LIST {GET, POST, DELETE};
		enum							INFO_LIST {LISTEN, SERVERNAME, ROOT, INDEX, METHODS, ERRORPAGE, CLIENTSIZE};
		std::map<std::string, int>		_info;

	private:
		std::vector<int>				_port;
		std::vector<std::string>		_host;
		std::vector<std::string>		_servName;
		std::vector<std::string>		_root;
		std::vector<std::string>		_index;
		std::vector<std::vector<bool>>	_avalMethods;

		int							_initCONFIG(const std::string confFile);

	public:
		CONFIG();
		CONFIG(char *confFile);
		CONFIG(const CONFIG &CONFIG);
		~CONFIG();

		CONFIG	&operator=(const CONFIG &CONFIG);
		
		const int				getPort() const;
		const std::string		getHost() const;
		const std::string		getServName() const;
		const std::vector<bool>	getAvalMethods() const;
};

#endif
