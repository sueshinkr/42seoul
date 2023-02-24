#include "config.hpp"

int						CONFIG::_initCONFIG(const std::string confFile)
{
	// .conf 읽기
	// 에러처리는 일단 넘기고 추후에 넣기로 하자...
	std::ifstream	confStream(confFile.c_str());
	std::string		line = "";

	if (!confStream.is_open())
		return (false);
	while (std::getline(confStream, line))
		;
	confStream.close();
	
	// 읽은 파일 파싱
	// server 블록 찾아서 파싱필요

	size_t	cur;
	size_t	brace;
	std::string	info = "";
	std::string data = "";

	_info["listen"] = LISTEN;
	_info["server_name"] = SERVERNAME;
	_info["root"] = ROOT;
	_info["index"] = INDEX;
	_info["methods"] = METHODS;
	_info["error_page"] = ERRORPAGE;
	_info["clinet_size"] = CLIENTSIZE;

	cur = line.find("server", 0);
	while (cur != std::string::npos)
	{
		int confIdx = 0;
		cur = line.find("{\n") + 3;
		while (line[cur] != '\t')
			info += line[cur++];
		while (line[cur] == '\t')
			cur++;
		while (line[cur] != '\n')
			data += line[cur++];

		switch (_info[info])
		{
			case LISTEN:
			{
				size_t sep = data.find(":");
				_host.push_back(data.substr(0, sep));
				_port.push_back(std::stoi(data.substr(sep, data.size())));
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
						start = std::string::npos;
					sep = data.find(" ");
				}
				_avalMethods.push_back(avalMethods);
				break;
			}
			case ERRORPAGE:
				break;
			case CLIENTSIZE:
				break;
		}
		cur = line.find("server", cur);
	}


	
}

const int				CONFIG::getPort() const
{
	return (_port);
}

const std::string		CONFIG::getHost() const
{
	return (_host);
}

const std::string		CONFIG::getServName() const
{
	return (_servName);
}

const std::vector<bool>	CONFIG::getAvalMethods() const
{
	return (_avalMethods);
}
