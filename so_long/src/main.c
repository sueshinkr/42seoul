/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:03:09 by sueshin           #+#    #+#             */
/*   Updated: 2022/10/11 19:41:17 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_enemy(t_data *d, int *w, int *h)
{
	d->ei = malloc(sizeof(t_enemy));
	d->ei->enemy_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/enemy.xpm", w, h);
	d->ei->enemy2_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/enemy2.xpm", w, h);
	d->ei->enemy_flag = 1;
	d->ei->enemy_num = 0;
}

static void	init_player(t_data *d, int *w, int *h)
{
	d->pi = malloc(sizeof(t_player));
	d->pi->front_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/front.xpm", w, h);
	d->pi->left_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/left.xpm", w, h);
	d->pi->back_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/back.xpm", w, h);
	d->pi->right_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/right.xpm", w, h);
	d->pi->front2_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/front2.xpm", w, h);
	d->pi->left2_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/left2.xpm", w, h);
	d->pi->back2_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/back2.xpm", w, h);
	d->pi->right2_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/right2.xpm", w, h);
	d->pi->front_flag = 0;
	d->pi->left_flag = 0;
	d->pi->back_flag = 1;
	d->pi->right_flag = 0;
}

static void	init_base(t_data *d, int *w, int *h)
{
	d->bi = malloc(sizeof(t_base));
	d->bi->grass_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/grass.xpm", w, h);
	d->bi->wall_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/wall.xpm", w, h);
	d->bi->col_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/collectible.xpm", w, h);
	d->bi->exit_img = mlx_xpm_file_to_image (d->mlx, \
		"./imageset/exit.xpm", w, h);
}

static void	init_data(t_data *d)
{
	int	w;
	int	h;

	d->mlx = mlx_init();
	d->win = NULL;
	d->move_count = 0;
	d->col = 0;
	d->row = 0;
	d->c_flag = 0;
	d->e_flag = 0;
	d->p_flag = 0;
	init_base(d, &w, &h);
	init_player(d, &w, &h);
	init_enemy(d, &w, &h);
}

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc != 2)
	{
		printf("Wrong input file : Error\n");
		return (0);
	}
	d = malloc(sizeof(t_data));
	init_data(d);
	open_map(argv[1], d);
	mlx_hook(d->win, 2, 0, &keypress, d);
	mlx_hook(d->win, 17, 0, &exit_game_with_red, d);
	mlx_loop_hook(d->mlx, &sel_animation, d);
	mlx_loop(d->mlx);
	return (0);
}
