/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:37:53 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/19 19:39:37 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "./get_next_line_bonus.h"

// Window resolution
# define width		640
# define height		480

// Texture resolution
# define texwidth	64
# define texheight	64

// Direction Index
# define NO			0
# define SO			1
# define WE			2
# define EA			3

// Key Number
# define K_UP		126
# define K_DOWN		125
# define K_LEFT		123
# define K_RIGHT	124
# define K_W		13
# define K_D		2
# define K_A		0
# define K_S		1
# define K_ESC		53

// Map Struct
typedef struct	s_map
{
	char	*temp_field;
	char	**field;
	int		col;
	int		row;
}				t_map;

// Player data
typedef struct	s_player
{
	// 위치벡터
	double	pos_x;
	double	pos_y;
	// 방향벡터
	double	dir_x;
	double	dir_y;
	// 카메라평면
	double	plane_x;
	double	plane_y;
	// 이동속도
	double	movsp;
	double	camsp;
}				t_player;

// Image Data
typedef struct	s_img
{
	void	*img;
	int		*data;
	int		sl;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_cub
{
	int			fd;
	int			count;
	int			**texture;
	int			buf[height][width + 1];
	int			rebuf;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color[3];
	int			ceiling_color[3];
}				t_cub;

typedef struct	s_camera
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perp_wdist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		wall_dir;
	double	step;
	double	texpos;
	int		color;
}			t_camera;

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	t_cub		cub;
	t_map		map;
	t_player	player;
	t_img		img;
}				t_info;

void	init_data(t_info *d);

void	open_cub(char *cub_file, t_info *d);

void	check_map_wall(t_map *map, char **field, int r, int c);
void	check_map_chr(t_info *d, char **field, int r, int c);

void	load_texture(t_info *d);
void	set_texture_base(t_player *p, t_camera *cam);
void	set_texture_buffer(t_info *d, t_camera *cam, int x, int y);

void	set_cam_base(t_player *p, t_camera *cam, int x);
void	set_dist_step(t_player *p, t_camera *cam);
void	run_dda(t_info *d, t_player *p, t_camera *cam, int hit);
void	set_drawposition(t_camera *cam);

int		keypress(int keycode, t_info *d);

void	move_up(t_map *map, t_player *p);
void	move_down(t_map *map, t_player *p);
void	move_left(t_map *map, t_player *p);
void	move_right(t_map *map, t_player *p);

void	camera_left(t_player *p);
void	camera_right(t_player *p);

void	exit_game(int flag);
int		exit_game_with_red(void);

char	*ft_strjoin_len(char *str1, char *str2, int len);
void	*ft_memset(void *ptr, int value, size_t size);
int		makecolor(int *color);

//add Function
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *str, char c);
void	free_arr(char **arr);
int		ft_atoi(const char *str);
int		is_emptyline(char *str);
int		is_space(char c);

#endif
