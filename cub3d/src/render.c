/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:21:44 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/16 16:29:39 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_cam_base(t_player *p, t_camera *cam, int x)
{
	cam->camera_x = 2 * x / (double)width - 1;
	cam->raydir_x = p->dir_x + p->plane_x * cam->camera_x;
	cam->raydir_y = p->dir_y + p->plane_y * cam->camera_x;
	cam->map_x = (int)p->pos_x;
	cam->map_y = (int)p->pos_y;
}

void	set_dist_step(t_player *p, t_camera *cam)
{
	cam->deltadist_x = fabs(1 / cam->raydir_x);
	cam->deltadist_y = fabs(1 / cam->raydir_y);
	if (cam->raydir_x < 0)
	{
		cam->step_x = -1;
		cam->sidedist_x = (p->pos_x - cam->map_x) * cam->deltadist_x;
	}
	else
	{
		cam->step_x = 1;
		cam->sidedist_x = (cam->map_x + 1.0 - p->pos_x) * cam->deltadist_x;
	}
	if (cam->raydir_y < 0)
	{
		cam->step_y = -1;
		cam->sidedist_y = (p->pos_y - cam->map_y) * cam->deltadist_y;
	}
	else
	{
		cam->step_y = 1;
		cam->sidedist_y = (cam->map_y + 1.0 - p->pos_y) * cam->deltadist_y;
	}
}

void	run_dda(t_info *d, t_player *p, t_camera *cam, int hit)
{
	while (hit == 0)
	{
		if (cam->sidedist_x < cam->sidedist_y)
		{
			cam->sidedist_x += cam->deltadist_x;
			cam->map_x += cam->step_x;
			cam->side = 0;
		}
		else
		{
			cam->sidedist_y += cam->deltadist_y;
			cam->map_y += cam->step_y;
			cam->side = 1;
		}
		if (d->map.field[cam->map_x][cam->map_y] == '1')
			hit = 1;
	}
	if (cam->side == 0)
		cam->perp_wdist = (cam->map_x - p->pos_x + (1 - cam->step_x) / 2)
			/ cam->raydir_x;
	else
		cam->perp_wdist = (cam->map_y - p->pos_y + (1 - cam->step_y) / 2)
			/ cam->raydir_y;
}

void	set_drawposition(t_camera *cam)
{
	cam->lineheight = (int)(height / cam->perp_wdist);
	cam->drawstart = -cam->lineheight / 2 + height / 2;
	if (cam->drawstart < 0)
		cam->drawstart = 0;
	cam->drawend = cam->lineheight / 2 + height / 2;
	if (cam->drawend >= height)
		cam->drawend = height - 1;
}
