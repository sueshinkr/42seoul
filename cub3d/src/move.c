/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:47:42 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/20 02:57:48 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_map *map, t_player *p)
{
	if (map->field[(int)(p->pos_x + p->dir_x * p->movsp)]
		[(int)(p->pos_y)] != '1')
		p->pos_x += p->dir_x * p->movsp;
	if (map->field[(int)(p->pos_x)]
		[(int)(p->pos_y + p->dir_y * p->movsp)] != '1')
		p->pos_y += p->dir_y * p->movsp;
}

void	move_down(t_map *map, t_player *p)
{
	if (map->field[(int)(p->pos_x - p->dir_x * p->movsp)]
		[(int)(p->pos_y)] != '1')
		p->pos_x -= p->dir_x * p->movsp;
	if (map->field[(int)(p->pos_x)]
		[(int)(p->pos_y - p->dir_y * p->movsp)] != '1')
		p->pos_y -= p->dir_y * p->movsp;
}

void	move_left(t_map *map, t_player *p)
{
	if (map->field[(int)(p->pos_x - p->plane_x * p->movsp)]
		[(int)(p->pos_y)] != '1')
		p->pos_x -= p->plane_x * p->movsp;
	if (map->field[(int)(p->pos_x)]
		[(int)(p->pos_y - p->plane_y * p->movsp)] != '1')
		p->pos_y -= p->plane_y * p->movsp;
}

void	move_right(t_map *map, t_player *p)
{
	if (map->field[(int)(p->pos_x + p->plane_x * p->movsp)]
		[(int)(p->pos_y)] != '1')
		p->pos_x += p->plane_x * p->movsp;
	if (map->field[(int)(p->pos_x)]
		[(int)(p->pos_y + p->plane_y * p->movsp)] != '1')
		p->pos_y += p->plane_y * p->movsp;
}
