#include "../include/config.hpp"

CONFIG::CONFIG()
{
	//_initCONFIG("default.conf");
}

CONFIG::CONFIG(const std::string confFile)
{
	_initCONFIG(confFile);
}

CONFIG::CONFIG(const CONFIG &config) : _port(config._port), _host(config._host), _servName(config._servName),
									   _root(config._root), _index(config._index), _avalMethods(config._avalMethods),
									   _servNum(config._servNum)
{

}

int						CONFIG::_initCONFIG(const std::string confFile)
{
	// .conf 읽기
	// 에러처리는 일단 넘기고 추후에 넣기로 하자...
	std::ifstream	confStream(confFile.c_str());
	std::string		line = "";
	std::string		temp;

	if (!confStream.is_open())
		return (false);
	while (std::getline(confStream, temp))
		line += temp + "\n";
	std::cout << "line : \n" << line << std::endl;
	confStream.close();
	
	// 읽은 파일 파싱
	// server 블록 찾아서 파싱필요

	size_t	cur = 0;
	int		brace = 0;
	
	_info["listen"] = LISTEN;
	_info["server_name"] = SERVERNAME;
	_info["root"] = ROOT;
	_info["index"] = INDEX;
	_info["methods"] = METHODS;
	_info["error_page"] = ERRORPAGE;
	_info["client_size"] = CLIENTSIZE;

	_servNum = 0;
	while ((cur = line.find("server", cur)) != std::string::npos)
	{
		_servNum++;
		if ((cur = line.find("{\n") + 2) != std::string::npos)
			brace++;
		while (line[cur++])
		{
			if (line[cur] == '}')
				break;
			else
				cur++;

			std::string	info = "";
			std::string data = "";

			while (line[cur] != '\t')
				info += line[cur++];
			while (line[cur] == '\t')
				cur++;
			while (line[cur] != '\n')
				data += line[cur++];

			std::cout << "info : " << info << " data : " << data << std::endl;
		
			switch (_info[info])
			{
				case LISTEN:
				{
					size_t sep = data.find(":");
					_host.push_back(data.substr(0, sep));
					std::string temp = data.substr(sep + 1, data.size());
					std::cout << "port : " << temp << std::endl;
					_port.push_back(std::stoi(temp));
					break;
				}
				case SERVERNAME:
				{
					_servName.push_back(data);
					break;
				}
				case ROOT:
				{
					_root.push_back(data);
					break;
				}
				case INDEX:
				{
					_index.push_back(data);
					break;
				}
				case METHODS:
				{
					std::vector<bool> avalMethods;

					for (int i = 0; i < 3; i++)
						avalMethods.push_back(false);
					size_t start = 0;
					size_t sep = data.find(" ");
					std::string method;

					while (start != std::string::npos)
					{
						method = data.substr(start, sep);
						if (method == "GET")
							avalMethods[GET] = true;
						else if (method == "POST")
							avalMethods[POST] = true; 
						else if (method == "DELETE")
							avalMethods[DELETE] = true;

						if (sep != std::string::npos)
							start = sep + 1;
						else
							break;
						sep = data.find(" ", sep + 1);
					}
					_avalMethods.push_back(avalMethods);
					break;
				}
				case ERRORPAGE:
					break;
				case CLIENTSIZE:
					break;
			}
		}
		
		
	}

	return (0);
}

int				CONFIG::getservNum() const
{
	return (_servNum);
}

int				CONFIG::getPort(int num) const
{
	return (_port[num]);
}

const std::string		CONFIG::getHost(int num) const
{
	return (_host[num]);
}

const std::string		CONFIG::getServName(int num) const
{
	return (_servName[num]);
}

const std::string		CONFIG::getRoot(int num) const
{
	return (_root[num]);
}

const std::string		CONFIG::getIndex(int num) const
{
	return(_index[num]);
}

const std::vector<bool>	CONFIG::getAvalMethods(int num) const
{
	return (_avalMethods[num]);
}
