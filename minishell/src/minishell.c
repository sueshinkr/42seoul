/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:27 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:53 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_data	*data;

	set_signal(argc, argv);
	set_terminal();
	data = init_data(envp);
	while (1)
	{
		line = readline("MINISHELL$ ");
		if (line)
		{
			if (ft_strlen(line) > 0)
				add_history(line);
			if (!check_empty(line))
			{
				init_tree(line, data);
				free_tree(data, data->head);
			}
			free(line);
			line = NULL;
		}
		else
			exit(-1);
	}
	return (0);
}
