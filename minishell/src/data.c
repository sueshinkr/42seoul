/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 16:11:00 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_empty(char *str)
{
	while (*str)
	{
		if (*str++ != ' ')
			return (0);
	}
	return (1);
}

static void	make_list(t_list *env, char **envp)
{
	int	idx;
	int	idx2;

	idx = -1;
	while (envp[++idx])
	{
		idx2 = -1;
		while (envp[idx][++idx2] != '=')
			;
		env->key = str_cut_front(envp[idx], idx2 + 1);
		env->value = str_cut_back(envp[idx], idx2);
		env->next = malloc(sizeof(t_list));
		env = env->next;
	}
	env = NULL;
}

t_data	*init_data(char **envp)
{
	t_data	*data;
	t_list	*env;

	data = malloc(sizeof(t_data));
	env = malloc(sizeof(t_list));
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->pipe_num = 0;
	data->err_flag = 0;
	data->cmd_cnt = -1;
	data->last_pipe[0] = -1;
	data->last_pipe[1] = -1;
	data->pid = 0;
	data->stdin_fd = dup(0);
	data->stdout_fd = dup(1);
	make_list(env, envp);
	data->env = env;
	return (data);
}

void	reset_data(t_data *data)
{
	close(data->last_pipe[0]);
	close(data->last_pipe[1]);
	close(data->infile_fd);
	close(data->outfile_fd);
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->last_pipe[0] = -1;
	data->last_pipe[1] = -1;
	data->cmd_cnt = -1;
	data->pipe_num = 0;
	data->err_flag = 0;
	data->pid = 0;
	dup2(data->stdin_fd, 0);
	dup2(data->stdout_fd, 1);
}

void	set_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
