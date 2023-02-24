#ifndef CONFIG_HPP
# define CONFIG_HPP
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iostream>

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
		std::vector<std::vector<bool> >	_avalMethods;
		int								_servNum;

		int							_initCONFIG(const std::string confFile);

	public:
		CONFIG();
		CONFIG(const std::string confFile);
		CONFIG(const CONFIG &config);
		//~CONFIG();

		//CONFIG	&operator=(const CONFIG &CONFIG);
		
		int				getservNum() const;
		int				getPort(int num) const;
		const std::string		getHost(int num) const;
		const std::string		getServName(int num) const;
		const std::string		getRoot(int num) const;
		const std::string		getIndex(int num) const;
		const std::vector<bool>	getAvalMethods(int num) const;
};

#endif
