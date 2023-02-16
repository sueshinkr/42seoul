#include "cub3d.h"

static void	set_cam_base(t_player *p, t_camera *cam, int x)
{
	cam->camera_x = 2 * x / (double)width - 1;
	cam->raydir_x = p->dir_x + p->plane_x * cam->camera_x;
	cam->raydir_y = p->dir_y + p->plane_y * cam->camera_x;
	cam->map_x = (int)p->pos_x;
	cam->map_y = (int)p->pos_y;
	
}

static void	set_dist_step(t_player *p, t_camera *cam)
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
		cam->perp_wdist = (cam->map_x - p->pos_x + (1 - cam->step_x) / 2 )
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

void	set_texture_base(t_player *p, t_camera *cam)
{
	if (cam->side == 0)
		cam->wall_x = p->pos_y + cam->perp_wdist * cam->raydir_y;
	else
		cam->wall_x = p->pos_x + cam->perp_wdist * cam->raydir_x;
	cam->wall_x -= floor(cam->wall_x);
	cam->tex_x = (int)(cam->wall_x * (double)texwidth);
	if (cam->side == 0 && cam->raydir_x > 0)
	{
		cam->wall_dir = SO;
		cam->tex_x = texwidth - cam->tex_x - 1;
	}
	else if (cam->side == 0 && cam->raydir_x < 0)
		cam->wall_dir = NO;
	else if (cam->side == 1 && cam->raydir_y < 0)
	{
		cam->wall_dir = WE;
		cam->tex_x = texwidth - cam->tex_x - 1;
	}
	else
		cam->wall_dir = EA;
}

void	set_texture_buffer(t_info *d, t_camera *cam, int x, int y)
{
	cam->step = 1.0 * texheight / cam->lineheight;
	cam->texpos = (cam->drawstart - height / 2 + cam->lineheight / 2)
		* cam->step;
	cam->color = makecolor(d->cub.ceiling_color);
	while (++y < cam->drawstart)
		d->cub.buf[y][x] = cam->color;
	while (y < cam->drawend)
	{
		cam->tex_y = (int)cam->texpos & (texheight - 1);
		cam->texpos += cam->step;
		cam->color = d->cub.texture[cam->wall_dir]
			[texheight * cam->tex_y + cam->tex_x];
		d->cub.buf[y][x] = cam->color;
		d->cub.rebuf = 1;
		y++;
	}
	cam->color = makecolor(d->cub.floor_color);
	while (y < height)
		d->cub.buf[y++][x] = cam->color;
}

void	raycasting(t_info *d, t_player *p)
{
	t_camera	cam;
	int			x;

	mlx_clear_window(d->mlx, d->win);

	x = 0;
	if (d->cub.rebuf == 1)
	{
		int i = -1;
		while (++i < height)
		{
			int j = -1;
			while (++j < width)
				d->cub.buf[i][j] = 0;
		}
	}
	while (x < width)
	{
		set_cam_base(p, &cam, x);
		set_dist_step(p, &cam);
		run_dda(d, p, &cam, 0);
		set_drawposition(&cam);

		// texture
		set_texture_base(p, &cam);
		set_texture_buffer(d, &cam, x, -1);
		x++;
	}
}