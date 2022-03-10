/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwon <tkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:54:53 by tkwon             #+#    #+#             */
/*   Updated: 2022/01/16 16:17:43 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

void	init_arr(char arr[][NUM])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < NUM)
	{
		j = 0;
		while (j < NUM)
		{
			arr[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	bool_space(char c, char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + cnt))
	{
		if (*(str + cnt) == c)
			return (cnt);
		cnt++;
	}
	return (-1);
}

int	check_input(char *str, char *condition)
{
	int	idx;
	int	con_idx;
	int	is_num;

	idx = 0;
	con_idx = 0;
	is_num = 0;
	while (str[idx])
	{
		if (str[idx] >= '1' && str[idx] <= '1' + NUM - 1 && is_num == 0)
		{
			if (con_idx++ == 16)
				return (0);
			condition[con_idx - 1] = str[idx];
			is_num = 1;
		}
		else if (bool_space(str[idx], "\t\n\v\f\r ") != -1)
			is_num = 0;
		else
			return (0);
		idx++;
	}
	if (con_idx == NUM * 4)
		return (1);
	return (0);
}

void	print_arr(char arr[][NUM])
{
	int	i;
	int	j;

	i = 0;
	while (i < NUM)
	{
		j = 0;
		while (j < NUM)
		{
			write(1, &arr[i][j], 1);
			if (j < NUM - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	condition[NUM * 4];
	char	array[NUM][NUM];
	int		result;

	init_arr(array);
	if (argc != 2)
		write(1, "Error\n", 6);
	else if (!check_input(argv[1], condition))
		write(1, "Error\n", 6);
	else
	{
		result = recur_board(condition, array, 0, 0);
		if (result == 0)
			write(1, "Error\n", 6);
		else
			print_arr(array);
	}
	return (0);
}
