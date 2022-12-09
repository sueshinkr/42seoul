/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:08 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:46 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	write_str(char **argvs, int mode)
{
	int	idx;

	if (mode == 1)
		idx = 1;
	else
		idx = 2;
	while (argvs[idx])
	{
		if (idx != mode)
			write(1, " ", 1);
		decode_text(argvs[idx]);
		write(1, argvs[idx], ft_strlen(argvs[idx]));
		idx++;
	}
	if (mode == 1)
		write(1, "\n", 1);
}

int	ft_echo(char **argvs)
{
	if (!argvs[1])
		write(1, "\n", 1);
	else if (ft_strcmp(argvs[1], "-n") == 0)
		write_str(argvs, 2);
	else
		write_str(argvs, 1);
	return (0);
}
