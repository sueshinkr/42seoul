/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:37:24 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/19 20:44:18 by taehyeok         ###   ########.fr       */
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
			if ((r == 0 || r == map->row - 1 || c == 0 || c == len - 1)
				&& !(f[r][c] == '1' || f[r][c] == ' '))
				exit_game(1);
			if (f[r][c] == ' ')
			{
				if (((r != map->row - 1 && f[r + 1][c])
					&& !(f[r + 1][c] == '1' || f[r + 1][c] == ' '))
					|| ((r != 0 && f[r - 1][c])
					&& !(f[r - 1][c] == '1' || f[r - 1][c] == ' '))
					|| ((c != len - 1 && f[r][c + 1])
					&& !(f[r][c + 1] == '1' || f[r][c + 1] == ' '))
					|| ((c != 0 && f[r][c - 1])
					&& !(f[r][c - 1] == '1' || f[r][c - 1] == ' ')))
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
