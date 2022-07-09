/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:41:27 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/10 02:03:02 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player_stop_motion_exit(t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, \
	(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
	mlx_put_image_to_window(d->mlx, d->win, d->bi->exit_img, \
	(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
	if (d->pi->front_flag == 1)
		mlx_put_image_to_window(d->mlx, d->win, d->pi->back2_img, \
		(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
	else
		mlx_put_image_to_window(d->mlx, d->win, d->pi->back_img, \
		(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
}

void	render_player_stop_motion1(t_data *d, int dir)
{
	mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, \
	(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
	if (dir == 1)
	{
		if (d->pi->front_flag == 1)
			mlx_put_image_to_window(d->mlx, d->win, d->pi->back2_img, \
			(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->pi->back_img, \
			(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
	}
	if (dir == 2)
	{
		if (d->pi->left_flag == 1)
			mlx_put_image_to_window(d->mlx, d->win, d->pi->left2_img, \
			(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->pi->left_img, \
			(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
	}
}

void	render_player_stop_motion2(t_data *d, int dir)
{
	mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, \
	(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
	if (dir == 3)
	{
		if (d->pi->back_flag == 1)
			mlx_put_image_to_window(d->mlx, d->win, d->pi->front2_img, \
			(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->pi->front_img, \
			(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
	}
	if (dir == 4)
	{
		if (d->pi->right_flag == 1)
			mlx_put_image_to_window(d->mlx, d->win, d->pi->right2_img, \
			(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->pi->right_img, \
			(d->p_loc % d->col) * 24, (d->p_loc / d->col) * 24);
	}
}

void	render_enemy_stop_motion(t_data *d, int idx)
{
	int	loc;

	if (d->ei->enemy_flag == 1)
	{
		while (++idx < d->ei->enemy_num)
		{
			loc = d->ei->enemy_loc[idx];
			mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, \
			(loc % d->col) * 24, (loc / d->col) * 24);
			mlx_put_image_to_window(d->mlx, d->win, d->ei->enemy_img, \
			(loc % d->col) * 24, (loc / d->col) * 24);
		}
	}
	else
	{
		while (++idx < d->ei->enemy_num)
		{
			loc = d->ei->enemy_loc[idx];
			mlx_put_image_to_window(d->mlx, d->win, d->bi->grass_img, \
			(loc % d->col) * 24, (loc / d->col) * 24);
			mlx_put_image_to_window(d->mlx, d->win, d->ei->enemy2_img, \
			(loc % d->col) * 24, (loc / d->col) * 24);
		}
	}
}
