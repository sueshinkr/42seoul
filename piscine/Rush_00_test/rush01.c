/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:10:06 by sueshin           #+#    #+#             */
/*   Updated: 2022/01/09 14:12:16 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_line(char left, char middle, char right, int x);

void	rush(int x, int y)
{
	if (y > 0)
	{
		ft_line('/', '*', '\\', x);
		y--;
	}
	while (y > 1)
	{
		ft_line('*', ' ', '*', x);
		y--;
	}
	if (y == 1)
		ft_line('\\', '*', '/', x);
}

void	ft_line(char left, char middle, char right, int x)
{
	if (x > 0)
	{
		ft_putchar(left);
		x--;
	}
	while (x > 1)
	{
		ft_putchar(middle);
		x--;
	}
	if (x == 1)
		ft_putchar(right);
	ft_putchar('\n');
}
