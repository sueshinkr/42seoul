/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:41:13 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/16 13:41:15 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map_player(t_map *map, t_player *player)
{
	map->temp_field = ft_strdup("");
	map->col = INT_MIN;
	map->row = 0;
	player->movsp = 0.15;
	player->camsp = 0.15;
}

static void	init_texture(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			cub->buf[i][j] = 0;
	}
	cub->texture = (int **)malloc(sizeof(int *) * 4);
	i = -1;
	while (++i < 4)
	{
		cub->texture[i] = (int *)malloc(sizeof(int) * texwidth * texheight);
		j = -1;
		while (++j < texwidth * texheight)
			cub->texture[i][j] = 0;
	}
	cub->rebuf = 0;
}

static void	init_cub(t_cub *cub)
{
	int	i;

	i = -1;
	cub->count = 0;
	while (++i < 3)
	{
		cub->floor_color[i] = 0;
		cub->ceiling_color[i] = 0;
	}
}

void	init_data(t_info *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, width, height, "cub3d");
	init_cub(&d->cub);
	init_map_player(&d->map, &d->player);
	init_texture(&d->cub);
}
