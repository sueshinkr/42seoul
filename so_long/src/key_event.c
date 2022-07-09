/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:54:27 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/10 02:02:34 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_data *d)
{
	int	new_loc;

	new_loc = d->p_loc - d->col;
	if (new_loc >= 0)
	{
		if (d->map[new_loc] == '1')
			return ;
		if (d->map[new_loc] == 'O')
			exit_game_with_map(7, d);
		if (d->map[new_loc] == 'E' || d->map[d->p_loc] == 'E')
		{
			if (d->c_flag == 0)
				exit_game_with_map(6, d);
			else
			{
				render_map_fail_exit(d, d->p_loc, new_loc);
				return ;
			}
		}
		else if (d->map[new_loc] == 'C')
			d->c_flag--;
		d->map[d->p_loc] = '0';
		d->map[new_loc] = 'P';
		render_map_after_move(d, d->p_loc, new_loc, 1);
	}
}

static void	move_down(t_data *d)
{
	int	new_loc;

	new_loc = d->p_loc + d->col;
	if (new_loc < d->col * d->row)
	{
		if (d->map[new_loc] == '1')
			return ;
		if (d->map[new_loc] == 'O')
			exit_game_with_map(7, d);
		if (d->map[new_loc] == 'E' || d->map[d->p_loc] == 'E')
		{
			if (d->c_flag == 0)
				exit_game_with_map(6, d);
			else
			{
				render_map_fail_exit(d, d->p_loc, new_loc);
				return ;
			}
		}
		else if (d->map[new_loc] == 'C')
			d->c_flag--;
		d->map[d->p_loc] = '0';
		d->map[new_loc] = 'P';
		render_map_after_move(d, d->p_loc, new_loc, 3);
	}
}

static void	move_left(t_data *d)
{
	int	new_loc;

	new_loc = d->p_loc - 1;
	if (d->p_loc % d->col != 0)
	{
		if (d->map[new_loc] == '1')
			return ;
		if (d->map[new_loc] == 'O')
			exit_game_with_map(7, d);
		if (d->map[new_loc] == 'E' || d->map[d->p_loc] == 'E')
		{
			if (d->c_flag == 0)
				exit_game_with_map(6, d);
			else
			{
				render_map_fail_exit(d, d->p_loc, new_loc);
				return ;
			}
		}
		else if (d->map[new_loc] == 'C')
			d->c_flag--;
		d->map[d->p_loc] = '0';
		d->map[new_loc] = 'P';
		render_map_after_move(d, d->p_loc, new_loc, 2);
	}
}

static void	move_right(t_data *d)
{
	int	new_loc;

	new_loc = d->p_loc + 1;
	if (d->p_loc % d->col != d->col - 1)
	{
		if (d->map[new_loc] == '1')
			return ;
		if (d->map[new_loc] == 'O')
			exit_game_with_map(7, d);
		if (d->map[new_loc] == 'E' || d->map[d->p_loc] == 'E')
		{
			if (d->c_flag == 0)
				exit_game_with_map(6, d);
			else
			{
				render_map_fail_exit(d, d->p_loc, new_loc);
				return ;
			}
		}
		else if (d->map[new_loc] == 'C')
			d->c_flag--;
		d->map[d->p_loc] = '0';
		d->map[new_loc] = 'P';
		render_map_after_move(d, d->p_loc, new_loc, 4);
	}
}

int	keypress(int keycode, t_data *d)
{
	if (keycode == 53)
		exit_game_with_map(5, d);
	else if (keycode == 13)
	{
		move_up(d);
		reset_animation_flag(d, 1);
	}
	else if (keycode == 0)
	{
		move_left(d);
		reset_animation_flag(d, 2);
	}
	else if (keycode == 1)
	{
		move_down(d);
		reset_animation_flag(d, 3);
	}
	else if (keycode == 2)
	{
		move_right(d);
		reset_animation_flag(d, 4);
	}
	print_count(d);
	printf("keycode : %d, count : %d\n", keycode, d->move_count);
	return (0);
}

// w 13 d 2 a 0 s 1 esc 53