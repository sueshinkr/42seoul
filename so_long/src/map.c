/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:33:23 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/11 14:36:58 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_map(t_data *d, int idx, int x, int y)
{
	int	temp;

	temp = 0;
	while (d->map[++idx])
	{
		y = (idx % d->col) * 24;
		x = (idx / d->col) * 24;
		mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, y, x);
		if (d->map[idx] == '1')
			mlx_put_image_to_window(d->mlx, d->win, d->bi->wall_img, y, x);
		else if (d->map[idx] == 'C')
			mlx_put_image_to_window(d->mlx, d->win, d->bi->col_img, y, x);
		else if (d->map[idx] == 'P')
		{
			d->p_loc = idx;
			mlx_put_image_to_window(d->mlx, d->win, d->pi->front_img, y, x);
		}
		else if (d->map[idx] == 'O')
		{
			d->ei->enemy_loc[temp++] = idx;
			mlx_put_image_to_window(d->mlx, d->win, d->ei->enemy_img, y, x);
		}
		else if (d->map[idx] == 'E')
			mlx_put_image_to_window(d->mlx, d->win, d->bi->exit_img, y, x);
	}
}

static void	check_map(t_data *d, int idx)
{
	if (ft_strlen(d->map) != (size_t)(d->col * d->row))
		exit_game_with_map(1);
	while (d->map[++idx])
	{
		if (!ft_strchr("01CPOE", d->map[idx]))
			exit_game_with_map(2);
		if ((idx < d->col || (idx >= d->col * (d->row - 1))
				|| idx % d->col == 0 || (idx % d->col == d->col - 1))
			&& (d->map[idx] != '1'))
			exit_game_with_map(3);
		if (d->map[idx] == 'C')
			d->c_flag++;
		if (d->map[idx] == 'E')
			d->e_flag++;
		if (d->map[idx] == 'P')
			d->p_flag++;
		if (d->map[idx] == 'O')
			d->ei->enemy_num++;
	}
	if (d->c_flag < 1 || d->e_flag < 1 || d->p_flag != 1)
		exit_game_with_map(4);
	d->ei->enemy_loc = malloc(d->ei->enemy_num * sizeof(int));
	d->win = mlx_new_window(d->mlx, 24 * d->col, 24 * (d->row + 1), "SoLong");
	render_map(d, -1, 0, 0);
}

	//맵이 직사각형모양인가 ok
	//벽이 둘러싸고있는가 ok
	//exit와 collectible이 하나 이상 존재하는가 ok
	//플레이어가 하나 존재하는가 ok
	//이상한게 꺄있지는 않은가 ok

void	open_map(char	*map_file, t_data *d)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit_game_with_map(0);
	else
	{
		d->col = ft_strlen(line);
		d->map = ft_strdup(line);
		while (line)
		{
			free(line);
			line = get_next_line(fd);
			if (line)
			{
				d->map = ft_strjoin(d->map, line);
				d->row++;
			}
		}
	}
	close(fd);
	check_map(d, -1);
	print_count_window(d);
}

void	render_map_after_move(t_data *d, int cur, int new, int dir)
{
	mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, \
	(cur % d->col) * 24, (cur / d->col) * 24);
	mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, \
	(new % d->col) * 24, (new / d->col) * 24);
	if (dir == 1)
		mlx_put_image_to_window(d->mlx, d->win, d->pi->back_img, \
		(new % d->col) * 24, (new / d->col) * 24);
	else if (dir == 2)
		mlx_put_image_to_window(d->mlx, d->win, d->pi->left_img, \
		(new % d->col) * 24, (new / d->col) * 24);
	else if (dir == 3)
		mlx_put_image_to_window(d->mlx, d->win, d->pi->front_img, \
		(new % d->col) * 24, (new / d->col) * 24);
	else if (dir == 4)
		mlx_put_image_to_window(d->mlx, d->win, d->pi->right_img, \
		(new % d->col) * 24, (new / d->col) * 24);
	d->move_count++;
	d->p_loc = new;
}

void	render_map_fail_exit(t_data *d, int cur, int new)
{
	if (d->map[new] == 'E')
	{
		mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, \
		(cur % d->col) * 24, (cur / d->col) * 24);
		mlx_put_image_to_window(d->mlx, d->win, d->pi->front_img, \
		(new % d->col) * 24, (new / d->col) * 24);
	}
	else if (d->map[cur] == 'E')
	{
		mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, \
		(cur % d->col) * 24, (cur / d->col) * 24);
		mlx_put_image_to_window(d->mlx, d->win, d->bi->exit_img, \
		(cur % d->col) * 24, (cur / d->col) * 24);
		reset_animation_flag(d, 1);
	}
	d->move_count++;
	d->p_loc = new;
}
