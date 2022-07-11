/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:00:08 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/11 14:38:02 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

static int	cal_count(int n)
{
	int				count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long long	nb;

	nb = n;
	count = cal_count(nb);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	*(str + count) = 0;
	while (nb > 0)
	{
		*(str + --count) = nb % 10 | '0';
		nb /= 10;
	}
	return (str);
}

void	print_count_console(t_data *d)
{
	char	*str;

	str = ft_itoa(d->move_count);
	ft_putstr_fd("movement count : ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
}

void	print_count_window(t_data *d)
{
	char	*str;
	int		idx;

	idx = -1;
	while (++idx < d->col)
		mlx_put_image_to_window(d->mlx, d->win, \
		d->bi->grass_img, idx * 24, 24 * d->row);
	str = ft_itoa(d->move_count);
	mlx_string_put(d->mlx, d->win, 6, 24 * d->row + 12, 0xffffff, "count : ");
	mlx_string_put(d->mlx, d->win, 60, 24 * d->row + 12, 0xffffff, str);
	free(str);
}
