/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwon <tkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:47:43 by tkwon             #+#    #+#             */
/*   Updated: 2022/01/16 16:07:38 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

char	loop_x1(char array[][NUM], int i)
{
	char	count;
	char	max;
	int		j;

	count = '1';
	max = array[0][i];
	j = 1;
	while (j < NUM)
	{
		if (max < array[j][i])
		{
			max = array[j][i];
			count++;
			if (max == NUM + '0')
				break ;
		}
		j++;
	}
	return (count);
}

char	loop_x2(char array[][NUM], int i)
{
	char	count;
	char	max;
	int		j;

	count = '1';
	max = array[NUM - 1][i];
	j = NUM - 2;
	while (j >= 0)
	{
		if (max < array[j][i])
		{
			max = array[j][i];
			count++;
			if (max == NUM + '0')
				break ;
		}
		j--;
	}
	return (count);
}

char	loop_y1(char array[][NUM], int i)
{
	char	count;
	char	max;
	int		j;

	count = '1';
	max = array[i][0];
	j = 1;
	while (j < NUM)
	{
		if (max < array[i][j])
		{
			max = array[i][j];
			count++;
			if (max == NUM + '0')
				break ;
		}
		j++;
	}
	return (count);
}

char	loop_y2(char array[][NUM], int i)
{
	char	count;
	char	max;
	int		j;

	j = NUM - 2;
	max = array[i][NUM - 1];
	count = '1';
	while (j >= 0)
	{
		if (max < array[i][j])
		{
			max = array[i][j];
			count++;
			if (max == NUM + '0')
				break ;
		}
		j--;
	}
	return (count);
}
