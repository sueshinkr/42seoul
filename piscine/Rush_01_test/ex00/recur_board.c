/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:35:21 by tkwon             #+#    #+#             */
/*   Updated: 2022/01/16 14:03:14 by sounchoi         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_condition(char *condition, char array[][NUM])
{
	int		i;

	i = 0;
	while (i < NUM)
	{
		if (loop_x1(array, i) != condition[i])
			return (0);
		if (loop_x2(array, i) != condition[i + NUM])
			return (0);
		i++;
	}
	i = 0;
	while (i < NUM)
	{
		if (loop_y1(array, i) != condition[i + NUM * 2])
			return (0);
		if (loop_y2(array, i) != condition[i + NUM * 3])
			return (0);
		i++;
	}
	return (1);
}

int	check_row_col(char array[][NUM], int x, int y)
{
	int	i;
	int	j;

	i = x;
	j = -1;
	while (++j < NUM)
	{
		if (i == x && j == y)
			continue ;
		if (array[i][j] == array[x][y])
			return (0);
	}
	i = -1;
	j = y;
	while (++i < NUM)
	{
		if (i == x && j == y)
			continue ;
		if (array[i][j] == array[x][y])
			return (0);
	}
	return (1);
}

int	recur_board(char *condition, char array[][NUM], int x, int y)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (x == NUM && y == 0)
		return (check_condition(condition, array));
	while (++i <= NUM)
	{
		array[x][y] = i + '0';
		if (check_row_col(array, x, y))
		{
			if (y == NUM - 1)
				result = recur_board(condition, array, x + 1, 0);
			else
				result = recur_board(condition, array, x, y + 1);
			if (result == 1)
				break ;
		}
		array[x][y] = '0';
	}
	return (result);
}
