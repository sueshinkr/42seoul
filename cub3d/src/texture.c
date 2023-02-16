/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:52:29 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/16 15:25:34 by sueshin          ###   ########.fr       */
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