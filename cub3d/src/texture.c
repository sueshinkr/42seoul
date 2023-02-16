/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:52:29 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/16 16:21:36 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_texture(t_info *d, int *texture, char *path)
{
	int	x;
	int	y;

	if (access(path, F_OK) == -1)
		exit_game(5);
	d->img.img = mlx_xpm_file_to_image
		(d->mlx, path, &d->img.img_width, &d->img.img_height);
	d->img.data = (int *)mlx_get_data_addr
		(d->img.img, &d->img.bpp, &d->img.sl, &d->img.endian);
	y = -1;
	while (++y < d->img.img_height)
	{
		x = -1;
		while (++x < d->img.img_width)
			texture[d->img.img_width * y + x]
				= d->img.data[d->img.img_width * y + x];
	}
	mlx_destroy_image(d->mlx, d->img.img);
}

void	load_texture(t_info *d)
{
	set_texture(d, d->cub.texture[0], d->cub.north_texture);
	set_texture(d, d->cub.texture[1], d->cub.south_texture);
	set_texture(d, d->cub.texture[2], d->cub.west_texture);
	set_texture(d, d->cub.texture[3], d->cub.east_texture);
}
// north-grass / south-stone / west-sand / east-oak

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
