/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:01:54 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/08 14:07:42 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int a, int b);
void	rush_row(int n, int m, int a);
void	rush_column(int n, int a);

void	rush(int a, int b)
{
	int n;
	int m;

	n = 0;
	m = 0;
	while (m < b )
	{
		if (m == 0 || m == b - 1 )
		{
			rush_row(n, m, a);
		}
		else
		{
			rush_column(n, a);
		}
		m++;
	}
}

void	rush_row(int n, int m, int a)
{
	while (n < a)
	{
		if (n == 0 || n == a - 1 )
		{
			if (m == 0 )
			{
				ft_putchar('A');
			}
			else
			{
				ft_putchar('C');
			}
		}
		else
		{
			ft_putchar('B');
		}
		n++;
	}
	ft_putchar('\n');
}

void	rush_column(int n, int a)
{
	while (n < a)
	{
		if (n == 0 || n == a - 1)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		n++;
	}
	ft_putchar('\n');
}
