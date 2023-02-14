#include "cub3d.h"

void	check_map_wall(t_map *map, char **field, int r, int c)
{
	int len;

	while (++r < map->row)
	{
		c = -1;
		len = ft_strlen(field[r]);
		while (++c < len)
		{
			if (field[r][c] == '0')
			{
				if (r == 0 || r == map->row - 1 || c == 0 || c == len - 1)
					exit_game_with_map(1);
				else if (r != 0 && (c >= ft_strlen(field[r - 1]) || 
				 		(c < ft_strlen(field[r - 1]) && field[r - 1][c] == ' ')))
					exit_game_with_map(1);
				else if (r != map->row - 1 && (c >= ft_strlen(field[r + 1]) ||
						(c < ft_strlen(field[r + 1]) && field[r + 1][c] == ' ')))
					exit_game_with_map(1);
				else if ((c != 0 && field[r][c - 1] == ' ') ||
						(c != len - 1 && field[r][c + 1] == ' '))
					exit_game_with_map(1);
			}
		}
	}
}

void	check_map_chr(t_cub *cub, char **field, int r, int c)
{
	int	len;
	int	count;

	count = 0;
	while (++r < cub->map->row)
	{
		c = -1;
		len = ft_strlen(field[r]);
		while (++c < len)
		{
			if (!(field[r][c] == '0' || field[r][c] == '1' ||
				field[r][c] == ' ' || field[r][c] == 'N' ||
				field[r][c] == 'S' || field[r][c] == 'W' || field[r][c] == 'E'))
				exit_game_with_map(2);
			if (field[r][c] == 'N' || field[r][c] == 'S' || 
				field[r][c] == 'W' || field[r][c] == 'E')
			{
				count++;
				cub->player->posX = r + 0.5;
				cub->player->posY = c + 0.5;
			}
			if (count > 1)
				exit_game_with_map(3);
		}
	}
}