/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:56:22 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/10 02:00:32 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_exit_animation(t_data *d)
{
	if (d->pi->front_flag == 1 || d->pi->front_flag == 5000)
		render_player_stop_motion_exit(d);
	d->pi->front_flag = d->pi->front_flag % 10000 + 1;
}

void	player_front_animation(t_data *d)
{
	if (d->pi->front_flag == 1 || d->pi->front_flag == 5000)
		render_player_stop_motion1(d, 1);
	d->pi->front_flag = d->pi->front_flag % 10000 + 1;
}

void	player_left_animation(t_data *d)
{
	if (d->pi->left_flag == 1 || d->pi->left_flag == 5000)
		render_player_stop_motion1(d, 2);
	d->pi->left_flag = d->pi->left_flag % 10000 + 1;
}

void	player_back_animation(t_data *d)
{
	if (d->pi->back_flag == 1 || d->pi->back_flag == 5000)
		render_player_stop_motion2(d, 3);
	d->pi->back_flag = d->pi->back_flag % 10000 + 1;
}

void	player_right_animation(t_data *d)
{
	if (d->pi->right_flag == 1 || d->pi->right_flag == 5000)
		render_player_stop_motion2(d, 4);
	d->pi->right_flag = d->pi->right_flag % 10000 + 1;
}
