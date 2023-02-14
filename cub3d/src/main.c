#include "cub3d.h"

void	verLine(t_info *d, int x, int drawStart, int drawEnd, int color)
{
	while (drawStart <= drawEnd)
	{
		mlx_pixel_put(d->mlx, d->win, x, drawStart, color);
		drawStart++;
	}
}

int	calc(t_info *d)
{
	int	x;

	x = 0;
	while (x < width)
	{
		double	cameraX = 2 * x / (double)width - 1;
		double	rayDirX = d->cub->player->dirX + d->cub->player->planeX * cameraX;
		double	rayDirY = d->cub->player->dirY + d->cub->player->planeY * cameraX;
		
		int	mapX = (int)d->cub->player->posX;
		int	mapY = (int)d->cub->player->posY;

		double	sideDistX;
		double	sideDistY;

		double	deltaDistX = fabs(1 / rayDirX);
		double	deltaDistY = fabs(1 / rayDirY);
		double	perpWallDist;

		int	stepX;
		int	stepY;

		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (d->cub->player->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - d->cub->player->posX) * deltaDistX;
		}

		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (d->cub->player->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - d->cub->player->posY) * deltaDistY;
		}

		if (x % 40 == 0)
		{
			printf("start loc : %d, %d\n", mapX, mapY);
			printf("deltaX : %f, deltaY : %f\n", deltaDistX, deltaDistY);
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (x % 40 == 0)
				printf("sideX, sideY : %f , %f, map : %d\n", sideDistX, sideDistY, d->cub->map->field[mapX][mapY] - '0');
			if (d->cub->map->field[mapX][mapY] > '0')
			{
				if (x % 40 == 0)
					printf("x : %d, mapX, mapY : %d, %d, side : %d\n\n", x, mapX, mapY, side);
				hit = 1;
			}
		}

		if (side == 0)
			perpWallDist = (mapX - d->cub->player->posX + (1 - stepX) / 2 ) / rayDirX;
		else
			perpWallDist = (mapY - d->cub->player->posY + (1 - stepY) / 2) / rayDirY;

		int	lineHeight = (int)(height / perpWallDist);
		int	drawStart = -lineHeight / 2 + height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if (drawEnd >= height)
			drawEnd = height - 1;
		
		int	color;
		color = 0xFF0000;
		if (side == 1)
			color = color / 2;
		
		verLine(d, x, drawStart, drawEnd, color);
		x++;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	t_info	*d;

	if (argc != 2)
	{
		printf("Wrong input file : Error\n");
		return (0);
	}
	d = malloc(sizeof(t_info));
	init_data(d);
	open_cub(argv[1], d);

	// CHECK
	printf("NO : %s\n", d->cub->north_texture);
	printf("SO : %s\n", d->cub->south_texture);
	printf("WE : %s\n", d->cub->west_texture);
	printf("EA : %s\n", d->cub->east_texture);

	printf("floor : %d %d %d\n", d->cub->floor_color[0], d->cub->floor_color[1], d->cub->floor_color[2]);
	printf("ceiling : %d %d %d\n", d->cub->ceiling_color[0], d->cub->ceiling_color[1], d->cub->ceiling_color[2]);

	printf("Map : \n");

	for (int i = 0; i < d->cub->map->row; i++)
	{
		printf("%s\n", d->cub->map->field[i]);
	}
	printf(":::: %f\n", d->cub->player->dirX);
	//sleep(5);

	//mlx_hook(d->win, 17, 0, &exit_game_with_red, NULL);
	mlx_loop_hook(d->mlx, &calc, d);
	mlx_loop(d->mlx);


	return 0;
}
/*
	mlx_hook(d->cub->win, 2, 0, &keypress, data);
	
	mlx_loop_hook(d->cub->mlx, &sel_animation, data);
	mlx_loop(d->cub->mlx);
*/
