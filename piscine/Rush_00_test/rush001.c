/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:48:51 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/08 14:51:16 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int a, int b);
void	rush_row(int row, int column, int a, int b);
void	rush_column(int column, int a);

void	rush(int a, int b)
{
	int row;
	int column;

	row = 0;
	column = 0;
	while (row < b )
	{
		if (row == 0 || row == b - 1 )
		{
			rush_row(row, column, a, b);
		}
		else
		{
			rush_column(column, a);
		}
		row++;
	}
}

void	rush_row(int row, int column, int a, int b)
{
	while (column < a)
	{
		if ((column == 0 && row == 0) || (column == a - 1 && row == b - 1 && b != 1 && a != 1))
		{
			ft_putchar('/');
		}
		else if ((column == a - 1 && row == 0) || (column == 0 && row == b - 1))
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('*');
		}
		column++;
	}
	ft_putchar('\n');
}

void	rush_column(int column, int a)
{
	while (column < a)
	{
		if (column == 0 || column == a - 1)
		{
			ft_putchar('*');
		}
		else
		{
			ft_putchar(' ');
		}
		column++;
	}
	ft_putchar('\n');
}
