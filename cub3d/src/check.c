/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:37:24 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/16 16:17:28 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_wall(t_map *map, char **f, int r, int c)
{
	int	len;

	while (++r < map->row)
	{
		c = -1;
		len = ft_strlen(f[r]);
		while (++c < len)
		{
			if (f[r][c] == '0')
			{
				if (r == 0 || r == map->row - 1 || c == 0 || c == len - 1)
					exit_game(1);
				else if (r != 0 && (c >= ft_strlen(f[r - 1])
						|| (c < ft_strlen(f[r - 1]) && f[r - 1][c] == ' ')))
					exit_game(1);
				else if (r != map->row - 1 && (c >= ft_strlen(f[r + 1])
						|| (c < ft_strlen(f[r + 1]) && f[r + 1][c] == ' ')))
					exit_game(1);
				if ((c != 0 && f[r][c - 1] == ' ') ||
						(c != len - 1 && f[r][c + 1] == ' '))
					exit_game(1);
			}
		}
	}
}

static void	set_ns(t_info *d, int r, int c, int *count)
{
	d->player.dir_y = 0;
	d->player.plane_x = 0;
	if (d->map.field[r][c] == 'N')
	{
		d->player.dir_x = -1;
		d->player.plane_y = 0.66;
	}
	else if (d->map.field[r][c] == 'S')
	{
		d->player.dir_x = 1;
		d->player.plane_y = -0.66;
	}
	d->player.pos_x = r + 0.5;
	d->player.pos_y = c + 0.5;
	(*count)++;
}

static void	set_we(t_info *d, int r, int c, int *count)
{
	d->player.dir_x = 0;
	d->player.plane_y = 0;
	if (d->map.field[r][c] == 'W')
	{
		d->player.dir_y = -1;
		d->player.plane_x = -0.66;
	}
	else if (d->map.field[r][c] == 'E')
	{
		d->player.dir_y = 1;
		d->player.plane_x = 0.66;
	}
	d->player.pos_x = r + 0.5;
	d->player.pos_y = c + 0.5;
	(*count)++;
}

void	check_map_chr(t_info *d, char **f, int r, int c)
{
	int	len;
	int	count;

	count = 0;
	while (++r < d->map.row)
	{
		c = -1;
		len = ft_strlen(f[r]);
		while (++c < len)
		{
			if (!(f[r][c] == '0' || f[r][c] == '1' ||
				f[r][c] == ' ' || f[r][c] == 'N' ||
				f[r][c] == 'S' || f[r][c] == 'W' ||
				f[r][c] == 'E'))
				exit_game(2);
			else if (f[r][c] == 'N' || f[r][c] == 'S')
				set_ns(d, r, c, &count);
			else if (f[r][c] == 'W' || f[r][c] == 'E')
				set_we(d, r, c, &count);
		}	
	}
	if (count != 1)
		exit_game(3);
}
