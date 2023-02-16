/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:30:37 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/16 13:33:01 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera_right(t_player *p)
{
	double	bfdir_x;
	double	bfplane_x;

	bfdir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-p->camsp) - p->dir_y * sin(-p->camsp);
	p->dir_y = bfdir_x * sin(-p->camsp) + p->dir_y * cos(-p->camsp);
	bfplane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-p->camsp) - p->plane_y * sin(-p->camsp);
	p->plane_y = bfplane_x * sin(-p->camsp) + p->plane_y * cos(-p->camsp);
}

void	camera_left(t_player *p)
{
	double	bfdir_x;
	double	bfplane_x;

	bfdir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(p->camsp) - p->dir_y * sin(p->camsp);
	p->dir_y = bfdir_x * sin(p->camsp) + p->dir_y * cos(p->camsp);
	bfplane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(p->camsp) - p->plane_y * sin(p->camsp);
	p->plane_y = bfplane_x * sin(p->camsp) + p->plane_y * cos(p->camsp);
}
