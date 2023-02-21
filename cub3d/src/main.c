/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:48:04 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/16 16:39:21 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_info *d, t_player *p)
{
	t_camera	cam;
	int			x;

	mlx_clear_window(d->mlx, d->win);
	if (d->cub.rebuf == 1)
		ft_memset(&d->cub.buf, 0, sizeof(d->cub.buf));
	x = 0;
	while (x < width)
	{
		ft_memset(&cam, 0, sizeof(t_camera));
		set_cam_base(p, &cam, x);
		set_dist_step(p, &cam);
		run_dda(d, p, &cam, 0);
		set_drawposition(&cam);
		set_texture_base(p, &cam);
		set_texture_buffer(d, &cam, x, -1);
		x++;
	}
}

void	draw(t_info *d)
{
	int	y;
	int	x;

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
	raycasting(d, &d->player);
	draw(d);
	return (0);
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
	open_cub(argv[1], d, -1);
	load_texture(d);
	d->img.img = mlx_new_image(d->mlx, width, height);
	d->img.data = (int *)mlx_get_data_addr
		(d->img.img, &d->img.bpp, &d->img.sl, &d->img.endian);
	mlx_hook(d->win, 17, 0, &exit_game_with_red, NULL);
	mlx_hook(d->win, 2, 0, &keypress, d);
	mlx_loop_hook(d->mlx, &cub3d, d);
	mlx_loop(d->mlx);
	return (0);
}

/* 추가로 해야될것

---------------완료
시작방위따라 방향벡터 조정 OK
움직임 OK
화면회전 OK
텍스쳐 추가 OK
방위따라 다른 텍스쳐 OK
천장 바닥 추가 OK
한칸짜리벽 통과하는거 손보기 OK
놈 OK

---------------진행중
맵파싱 좀더 손보기
릭체크
에러처리 보완

*/