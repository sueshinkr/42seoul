/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:37:53 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/13 18:58:32 by sueshin          ###   ########.fr       */
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

#include "../mlx/mlx.h"
#include "./get_next_line_bonus.h"

typedef struct	s_map
{
	char	*temp_field;
	char	**field;
	int		col;
	int		row;
}				t_map;

typedef struct	s_cub
{
	int		fd;
	int		count;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	t_map	*map;
}				t_cub;

typedef struct	s_info
{
/*
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double	moveSpeed;
	double	rotSpeed;
*/
	void	*mlx;
	void	*win;
	t_cub	*cub;
}				t_info;

void	exit_game_with_map(int flag);
char	*ft_strjoin_len(char *str1, char *str2, int len);

#endif
