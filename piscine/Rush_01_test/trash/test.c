#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int clue[16];
	int i;
	int j;
	int flag;

	i = -1;
	j = 0;
	flag = 0;
	while (argv[1][++i])
	{
		if (flag == 0 && argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			clue[j++] = argv[1][i] - '0';
			flag = 1;
		}	
		else if ( (flag == 1 && argv[1][i] != ' ') ||
				(flag == 0 && argv[1][i] == ' ') ||
				(argv[1][i] < '1' && argv[1][i] > '4' && argv[1][i]!= ' ') 
				|| j >= 16)
		{
			write(1, "ERROR\n", 6);
			return 0;
		}
		else if (flag == 1 && argv[1][i] == ' ')
			flag = 0;
	}
	if (j != 16 || argc != 2)
	{
		write(1, "ERROR\n", 6);
		return 0;
	}	
}









