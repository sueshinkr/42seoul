#include "cub3d.h"

static void	init_map(t_map *map)
{
	map->temp_field = ft_strdup("");
	map->col = INT_MIN;
	map->row = 0;
}

static void	init_player(t_player *player)
{
	player->dirX = -1;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = 0.66;
	player->movsp = 0.05;
	player->camsp = 0.05;
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
	cub->map = malloc(sizeof(t_map));
	cub->player = malloc(sizeof(t_player));
	init_map(cub->map);
	init_player(cub->player);
}

void	init_data(t_info *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, width, height, "cub3d");
	d->cub = malloc(sizeof(t_cub));
	init_cub(d->cub);
}
