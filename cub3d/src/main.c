#include "cub3d.h"

void	calc(t_info *d)
{
	int	x;

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
		double	cameraX = 2 * x / (double)width - 1;
		double	rayDirX = d->player.dirX + d->player.planeX * cameraX;
		double	rayDirY = d->player.dirY + d->player.planeY * cameraX;
		
		int	mapX = (int)d->player.posX;
		int	mapY = (int)d->player.posY;

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
			sideDistX = (d->player.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - d->player.posX) * deltaDistX;
		}

		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (d->player.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - d->player.posY) * deltaDistY;
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
			if (d->map.field[mapX][mapY] > '0')
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (mapX - d->player.posX + (1 - stepX) / 2 ) / rayDirX;
		else
			perpWallDist = (mapY - d->player.posY + (1 - stepY) / 2) / rayDirY;

		int	lineHeight = (int)(height / perpWallDist);
		
		int	drawStart = -lineHeight / 2 + height / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if (drawEnd >= height)
			drawEnd = height - 1;

		// texture
		double wallX;
		if (side == 0)
			wallX = d->player.posY + perpWallDist * rayDirY;
		else
			wallX = d->player.posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)texwidth);
		if (side == 0 && rayDirX > 0)
			texX = texwidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texwidth - texX - 1;
		
		double step = 1.0 * texheight / lineHeight;
		double texPos = (drawStart - height / 2 + lineHeight / 2) * step;
		
		int y;
		y = drawStart;
		while (y < drawEnd)
		{
			int texY = (int)texPos & (texheight - 1);
			texPos += step;
			int color = d->cub.texture[0][texheight * texY + texX];
			if (side == 0)
				color = (color >> 1) & 8355711;
			d->cub.buf[y][x] = color;
			d->cub.rebuf = 1;
			y++;
		}
		x++;
	}
}

void	load_texture(t_info *d, int *texture, char *path)
{
	int	x;
	int	y;

	d->img.img = mlx_xpm_file_to_image(d->mlx, path, &d->img.img_width, &d->img.img_height);
	d->img.data = (int *)mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.sl, &d->img.endian);
	y = -1;
	while (++y < d->img.img_height)
	{
		x = -1;
		while (++x < d->img.img_width)
			texture[d->img.img_width * y + x] = d->img.data[d->img.img_width * y + x]; // img->img_width * y + x
	}
	mlx_destroy_image(d->mlx, d->img.img);
}

void	draw(t_info *d)
{
	int	y;
	int x;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			d->img.data[y * width + x] = d->cub.buf[y][x];
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
}


int	cub3d(t_info *d)
{
	calc(d);
	draw(d);
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
	printf("----\n");
	open_cub(argv[1], d);

	/*// CHECK
	printf("NO : %s\n", d->cub.north_texture);
	printf("SO : %s\n", d->cub.south_texture);
	printf("WE : %s\n", d->cub.west_texture);
	printf("EA : %s\n", d->cub.east_texture);

	printf("floor : %d %d %d\n", d->cub.floor_color[0], d->cub.floor_color[1], d->cub.floor_color[2]);
	printf("ceiling : %d %d %d\n", d->cub.ceiling_color[0], d->cub.ceiling_color[1], d->cub.ceiling_color[2]);

	printf("Map : \n");

	for (int i = 0; i < d->map.row; i++)
	{
		printf("%s\n", d->map.field[i]);
	}
	*/
	
	load_texture(d, d->cub.texture[0], d->cub.north_texture);
	load_texture(d, d->cub.texture[1], d->cub.south_texture);
	load_texture(d, d->cub.texture[2], d->cub.west_texture);
	load_texture(d, d->cub.texture[3], d->cub.east_texture);

	printf("--------------\n");

	d->img.img = mlx_new_image(d->mlx, width, height);
	d->img.data = (int *)mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.sl, &d->img.endian);

	mlx_hook(d->win, 17, 0, &exit_game_with_red, NULL);
	mlx_hook(d->win, 2, 0, &keypress, d);
	mlx_loop_hook(d->mlx, &cub3d, d);
	mlx_loop(d->mlx);

	return 0;
}

/* 추가로 해야될것
시작방위따라 방향벡터 조정 OK
움직임 OK
화면회전 OK
텍스쳐 추가 OK?
방위따라 다른 텍스쳐
천장 바닥 추가
맵파싱 좀더 손보기
*/

