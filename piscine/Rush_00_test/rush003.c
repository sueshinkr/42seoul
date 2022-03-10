/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:09:07 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/08 14:14:45 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int a, int b);
void	rush_row(int n, int a);
void	rush_column(int n, int a);

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
			rush_row(column, a);
		}
		else
		{
			rush_column(column, a);
		}
		row++;
	}
}

void	rush_row(int column, int a)
{
	while (column < a)
	{
		if (column == 0 )
		{
			ft_putchar('A');
		}
		else if (column == a - 1 )
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
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
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		column++;
	}
	ft_putchar('\n');
}
