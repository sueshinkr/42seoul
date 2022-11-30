#include "minishell.h"

void	free_arr(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}

char	*ft_strjoin_pipex(char *str1, char *str2)
{
	char	*joinstr;
	size_t	joinstr_len;
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	idx2 = 0;
	joinstr_len = strlen(str1) + strlen(str2) + 1;
	joinstr = (char *)malloc(joinstr_len * sizeof(char));
	if (!joinstr)
		return (NULL);
	while (*(str1 + idx1))
	{
		*(joinstr + idx1) = *(str1 + idx1);
		idx1++;
	}
	while (*(str2 + idx2))
	{
		*(joinstr + idx1 + idx2) = *(str2 + idx2);
		idx2++;
	}
	*(joinstr + idx1 + idx2) = 0;
	return (joinstr);
}

static char	*check_slash(char *path, char *cmd)
{
	char	*temp;
	char	*ret;
	int		len;

	if (cmd[0] == '/')
		return (strdup(cmd));
	len = strlen(path);
	if (path[len - 1] == '/')
		ret = ft_strjoin_pipex(path, cmd);
	else
	{
		temp = ft_strjoin_pipex("/", cmd);
		ret = ft_strjoin_pipex(path, temp);
		free(temp);
	}
	return (ret);
}

int	is_inslash(char *s)
{
	while (*s)
	{
		if (*s == '/')
			return (1);
		s++;
	}
	return (0);
}

char	*ret_path(t_data *data, char **path, char *cmd)
{
	char	*str;
	int		idx;

	idx = 0;
	while (path[idx])
	{
		str = check_slash(path[idx], cmd);
		if (!access(str, F_OK))
		{
			free_arr(path);
			return (str);
		}
		else
			free(str);
		idx++;
	}
	data->exit_code = 127;
	free_arr(path);
	return (NULL);
}

char	*check_path(t_list *env, t_data *data, char *cmd)
{
	char	**path;

	path = 0;
	if (is_inslash(cmd) && !access(cmd, F_OK))
	{
		if (!access(cmd, X_OK))
			return (cmd);
		data->exit_code = 126;
		return (NULL);
	}
	while (env->key)
	{
		if (!strcmp(env->key, "PATH"))
			path = ft_split(env->value, ':');
		env = env->next;
	}
	if (path == NULL)
		return (NULL);
	return (ret_path(data, path, cmd));
}

void	do_exec(t_data *data, char *cmd_path, char **cmd_str, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork :");
		exit(1);
	}
	if (pid == 0)
	{
		execve(cmd_path, cmd_str, env);
		perror(cmd_str[0]);
		exit(errno);
	}
	waitpid(pid, &data->exit_code, 0);
}

void	pipe_in(char *cmd_path, char **cmd_str, char **env, t_data *data)
{
	if (!strcmp(cmd_str[0], "echo"))
		data->exit_code = ft_echo(cmd_str);
	else if (!strcmp(cmd_str[0], "cd"))
		data->exit_code = ft_cd(cmd_str, data);
	else if (!strcmp(cmd_str[0], "pwd"))
		data->exit_code = ft_pwd(cmd_str);
	else if (!strcmp(cmd_str[0], "export"))
		data->exit_code = ft_export(cmd_str, data);
	else if (!strcmp(cmd_str[0], "unset"))
		data->exit_code = ft_unset(cmd_str, data);
	else if (!strcmp(cmd_str[0], "env"))
		data->exit_code = ft_env(cmd_str, data->env);
	else if (!strcmp(cmd_str[0], "exit"))
		data->exit_code = ft_exit(cmd_str);
	else
		execve(cmd_path, cmd_str, env);
	exit(data->exit_code);
}

char	**make_env(t_data *data)
{
	int		len;
	t_list	*temp;
	char	**env;
	char	*tmp;
	int		idx;

	len = 0;
	temp = data->env;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	env = malloc((len + 1) * sizeof(char *));
	temp = data->env;
	idx = -1;
	while (temp->key)
	{
		if (temp->value)
		{
			env[++idx] = strdup(temp->key);
			tmp = env[idx];
			env[idx] = ft_strjoin_pipex(env[idx], "=");
			free(tmp);
			tmp = env[idx];
			env[idx] = ft_strjoin_pipex(env[idx], temp->value);
			free(tmp);
			tmp = NULL;
		}
		temp = temp->next;
	}
	env[++idx] = 0;
	return (env);
}

int		is_builtin(t_data *data, char **cmd_str)
{
	if (!strcmp(cmd_str[0], "echo"))
		data->exit_code = ft_echo(cmd_str);
	else if (!strcmp(cmd_str[0], "cd"))
		data->exit_code = ft_cd(cmd_str, data);
	else if (!strcmp(cmd_str[0], "pwd"))
		data->exit_code = ft_pwd(cmd_str);
	else if (!strcmp(cmd_str[0], "export"))
		data->exit_code = ft_export(cmd_str, data);
	else if (!strcmp(cmd_str[0], "unset"))
		data->exit_code = ft_unset(cmd_str, data);
	else if (!strcmp(cmd_str[0], "env"))
		data->exit_code = ft_env(cmd_str, data->env);
	else if (!strcmp(cmd_str[0], "exit"))
		data->exit_code = ft_exit(cmd_str);
	else
		return (0);
	return (1);
}

void	prt_execute_err(t_data *data)
{
	if (data->exit_code == 126)
		write(2, "permission denied\n", ft_strlen_gnl("permission denied\n"));
	else
		write(2, "command not found\n", ft_strlen_gnl("command not found\n"));
	return ;
}

void	single_cmd(t_data *data, char **cmd_str, char **env)
{
	char		*cmd_path;

	if (is_builtin(data, cmd_str))
		;
	else
	{
		cmd_path = check_path(data->env, data, cmd_str[0]);
		if (!cmd_path)
		{
			prt_execute_err(data);
			return ;
		}
		do_exec(data, cmd_path, cmd_str, env);
		free(cmd_path);
	}
}

void	dup_src(int *p)
{
	dup2(p[1], 1);
	close(p[0]);
}

void	dup_dest(t_data *data, int *p)
{
	if (data->infile_fd == -1)
		dup2(data->last_pipe[0], 0);
	else
		dup2(data->infile_fd, 0);
	if (data->cmd_cnt < data->pipe_num)
	{
		dup2(p[1], 1);
		close(p[0]);
	}
	else
	{
		dup2(data->outfile_fd, 1);
	}
	close(data->last_pipe[1]);
}

void	close_pipe(t_data *data, int *p)
{
	close(data->last_pipe[0]);
	close(data->last_pipe[1]);
	data->last_pipe[0] = p[0];
	data->last_pipe[1] = p[1];
}

void	pipe_cmd(t_data *data, char **cmd_str, char **env)
{
	char	*cmd_path;
	pid_t	pid;
	int		p[2];

	cmd_path = check_path(data->env, data, cmd_str[0]);
	if (!cmd_path)
		return (prt_execute_err(data));
	if (pipe(p) == -1)
	{
		perror("Pipe Error : ");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (data->last_pipe[0] == -1)
			dup_src(p);
		else
			dup_dest(data, p);
		pipe_in(cmd_path, cmd_str, env, data);
	}
	data->pid = pid;
	close_pipe(data, p);
	free(cmd_path);
}

void	set_scmd(t_data *data, node *n)
{
	char	**cmd_str;
	char	**env;

	data->cmd_cnt++;
	cmd_str = ft_split(n->node_str, ' ');
	env = make_env(data);
	if (data->pipe_num < 1)
		single_cmd(data, cmd_str, env);
	else
		pipe_cmd(data, cmd_str, env);
	free_arr(cmd_str);
	free_arr(env);
}