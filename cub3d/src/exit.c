#include "cub3d.h"

void	exit_game_with_map(int flag)
{
	if (flag == 0)
		printf("Empty input map : Error\n");
	else if (flag == 1)
		printf("Wrong wall : Error\n");
	else if (flag == 2)
		printf("Wrong character input : Error\n");
	else if (flag == 3)
		printf("More than one player : Error\n");
	else if (flag == 4)
		printf("Wrong color range : Error\n");
	else if (flag == 5)
		printf("Exit Game...\n");
	else if (flag == 6)
		printf("Game Clear!\n");
	else if (flag == 7)
		printf("Don't touch the cow!\n");
	//exit(0);
}

int	exit_game_with_red(void)
{
	printf("Exit Game...\n");
	exit(0);
}