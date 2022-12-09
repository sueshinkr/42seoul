/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:16 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:50 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **argvs)
{
	char	*path;

	(void)argvs;
	path = getcwd(NULL, 0);
	if (path == NULL)
		return (1);
	ft_printf("%s\n", path);
	free(path);
	return (0);
}
