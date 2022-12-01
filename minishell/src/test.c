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

void	make_list(t_list *env, char **envp)
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
	data->stdin_fd = dup(0);
	data->stdout_fd = dup(1);
	make_list(env, envp);
	data->env = env;
	return (data);
}

static void	set_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_data	*data;

	set_signal(argc, argv);
	set_terminal();
	data = init_data(envp);
	while (1)
	{
		data->pipe_num = 0;
		line = readline("MINISHELL$ ");
		if (line)
		{
			add_history(line);
			if (check_empty(line))
				continue ;
			init_tree(line, data);
			free_tree(data, data->head);
			free(line);
			line = NULL;
		}
		else
			exit(-1);
	}
	return (0);
}
