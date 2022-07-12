/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:37:53 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/12 14:01:23 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG2_H
# define SO_LONG2_H

# include <stdlib.h>
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

#endif
