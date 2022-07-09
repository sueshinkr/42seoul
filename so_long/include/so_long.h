#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "../mlx/mlx.h"
# include "./get_next_line.h"

typedef struct s_enemy
{
	void	*enemy_img;
	void	*enemy2_img;
	int		enemy_flag;
} t_enemy;

typedef struct	s_player
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

typedef struct	s_mlx
{
	void			*mlx;
	void			*win;
	void			*grass_img;
	void			*wall_img;
	void			*collectible_img;
	void			*exit_img;
	t_player	*pi;
	t_enemy		*ei;
}	t_mlx;

typedef struct	s_data
{
	t_mlx	*base;
	char	*map;
	int		column;
	int		row;
	int		C_flag;
	int		E_flag;
	int		P_flag;
	int		P_location;
	int		move_count;
}	t_data;

void	open_map(char	*map_file, t_data *data);
void	check_map(t_data *data);
void	render_map(t_data *data);
void	render_map_after_move(t_data *data, int cur, int new, int dir);
void	render_map_fail_exit(t_data *data, int cur, int new);
void	render_player_stop_motion1(t_data *data, int dir);
void	render_player_stop_motion2(t_data *data, int dir);
void	render_enemy_stop_motion(t_data *data);
int		keypress(int keycode, t_data *data);
void	exit_game_with_map(int flag, t_data *data);
int		exit_game_with_red();
void	print_count(t_data *data);
char	*ft_itoa(int n);
int		cal_count(int n);
int		sel_animation(t_data *data);
void	sel_player_animation(t_data *data);
void	player_exit_animation(t_data *data);
void	player_front_animation(t_data *data);
void	player_left_animation(t_data *data);
void	player_back_animation(t_data *data);
void	player_right_animation(t_data *data);
void	enemy_animation(t_data *data);
void	reset_animation_flag(t_data *data, int cur);


#endif