/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:37:53 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/14 21:43:58 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#include "../mlx/mlx.h"
#include "./get_next_line_bonus.h"

#define width		640
#define height		480
#define texwidth	64
#define texheight	48

typedef struct	s_map
{
	char	*temp_field;
	char	**field;
	int		col;
	int		row;
}				t_map;

typedef struct	s_player
{
	// 위치벡터
	double	posX;
	double	posY;
	// 방향벡터
	double	dirX;
	double	dirY;
	// 카메라평면
	double	planeX;
	double	planeY;
	// 이동속도
	double	movsp;
	double	camsp;
}				t_player;

typedef struct	s_cub
{
	int			fd;
	int			count;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	t_map		*map;
	t_player	*player;
}				t_cub;

typedef struct	s_info
{
	double	moveSpeed;
	double	rotSpeed;

	void	*mlx;
	void	*win;
	t_cub	*cub;
}				t_info;

void	init_data(t_info *d);

void	open_cub(char *cub_file, t_info *d);

void	check_map_wall(t_map *map, char **field, int r, int c);
void	check_map_chr(t_cub *cub, char **field, int r, int c);

int	keypress(int keycode, t_info *d);

void	exit_game_with_map(int flag);
int		exit_game_with_red(void);
char	*ft_strjoin_len(char *str1, char *str2, int len);

#endif
