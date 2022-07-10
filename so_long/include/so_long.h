/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:37:53 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/10 22:20:01 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "../mlx/mlx.h"
# include "./get_next_line_bonus.h"

typedef struct s_enemy
{
	void	*enemy_img;
	void	*enemy2_img;
	int		enemy_flag;
	int		enemy_num;
	int		*enemy_loc;
}	t_enemy;

typedef struct s_player
{
	void	*front_img;
	void	*front2_img;
	void	*back_img;
	void	*back2_img;
	void	*left_img;
	void	*left2_img;
	void	*right_img;
	void	*right2_img;
	int		front_flag;
	int		back_flag;
	int		left_flag;
	int		right_flag;
}	t_player;

typedef struct s_base
{
	void			*grass_img;
	void			*wall_img;
	void			*col_img;
	void			*exit_img;
}	t_base;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*map;
	int			col;
	int			row;
	int			c_flag;
	int			e_flag;
	int			p_flag;
	int			p_loc;
	int			move_count;
	t_base		*bi;
	t_player	*pi;
	t_enemy		*ei;
}	t_data;

void	open_map(char	*map_file, t_data *d);
void	render_map_after_move(t_data *d, int cur, int new, int dir);
void	render_map_fail_exit(t_data *d, int cur, int new);

void	render_player_stop_motion_exit(t_data *d);
void	render_player_stop_motion1(t_data *d, int dir);
void	render_player_stop_motion2(t_data *d, int dir);
void	render_enemy_stop_motion(t_data *d, int idx);

int		keypress(int keycode, t_data *d);

void	exit_game_with_map(int flag, t_data *d);
int		exit_game_with_red(void);

int		sel_animation(t_data *d);
void	reset_animation_flag(t_data *d, int cur);
void	player_exit_animation(t_data *d);
void	player_front_animation(t_data *d);
void	player_left_animation(t_data *d);
void	player_back_animation(t_data *d);
void	player_right_animation(t_data *d);

char	*ft_itoa(int n);
void	print_count(t_data *d);

#endif
