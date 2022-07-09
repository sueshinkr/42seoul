/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:55:42 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/10 02:00:26 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sel_player_animation(t_data *d)
{
	if (d->map[d->p_loc] == 'E')
		player_exit_animation(d);
	else if (d->pi->front_flag != 0)
		player_front_animation(d);
	else if (d->pi->left_flag != 0)
		player_left_animation(d);
	else if (d->pi->back_flag != 0)
		player_back_animation(d);
	else if (d->pi->right_flag != 0)
		player_right_animation(d);
}

static void	enemy_animation(t_data *d)
{
	if (d->ei->enemy_flag == 1 || d->ei->enemy_flag == 5000)
		render_enemy_stop_motion(d, -1);
	d->ei->enemy_flag = d->ei->enemy_flag % 10000 + 1;
}

int	sel_animation(t_data *d)
{
	sel_player_animation(d);
	enemy_animation(d);
	return (0);
}

void	reset_animation_flag(t_data *d, int cur)
{
	d->pi->front_flag = 0;
	d->pi->back_flag = 0;
	d->pi->left_flag = 0;
	d->pi->right_flag = 0;
	if (cur == 1)
		d->pi->front_flag = 1;
	else if (cur == 2)
		d->pi->left_flag = 1;
	else if (cur == 3)
		d->pi->back_flag = 1;
	else if (cur == 4)
		d->pi->right_flag = 1;
}
