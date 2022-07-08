#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "../mlx/mlx.h"
# include "./get_next_line.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*grass_img;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
} t_mlx;

typedef struct s_data
{
	t_mlx	*base;
	char	*map;
	int		column;
	int		row;
	int		C_flag;
	int		E_flag;
	int		P_flag;
	int		P_location;
	int		key_count;
}	t_data;

void	open_map(char	*map_file, t_data *data);
void	check_map(t_data *data);
void	render_map(t_data *data);
void	render_map_after_move(t_data *data, int cur, int new);
void	render_map_fail_exit(t_data *data, int cur, int new);
int		keypress(int keycode, t_data *data);
void	exit_game_with_map(int flag, t_data *data);
int		exit_game_with_red();
void	print_count(t_data *data);
char	*ft_itoa(int n);
int		cal_count(int n);
void	move_up(t_data *data);

#endif