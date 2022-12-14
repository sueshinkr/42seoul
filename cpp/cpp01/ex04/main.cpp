#include <iostream>
#include <fstream>

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong Argument : Argument must be [filename s1 s2]\n";
		return 1;
	}

	std::string file = argv[1];
	std::ifstream fin(file);
	if (!fin.is_open())
	{
		std::cout << "Can't open File. Try again!\n";
		return 1;
	}

	std::string	temp;
	char		ch;
	while (fin.get(ch))
		temp += ch;
	fin.close();

	size_t	pos;
	while ((pos = temp.find(argv[2])) != std::string::npos)
	{
		temp.erase(pos, strlen(argv[2]));
		temp.insert(pos, argv[3]);
	}

	std::string newfile = file + ".replace";
	std::ofstream fout(newfile);
	if (!fout.is_open())
	{
		std::cout << "Can't open File.replace. Try again!\n";
		return 1;
	}
	fout << temp;
	fout.close();

	std::cout << "Copy and Replace Success!\n";

	return 0;
}
