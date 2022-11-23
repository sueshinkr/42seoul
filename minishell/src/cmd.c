#include "minishell.h"

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

char	*check_path(t_list *env, char *cmd)
{
	char	*str;
	char	**path;
	while (env->key)
	{
		if (!strcmp(env->key, "PATH"))
			path = ft_split(env->value, ':');
		env = env->next;
	}

	while (*path)
	{
		str = check_slash(*path, cmd);
		if (!access(str, F_OK))
			return (str);
		else
			free(str);
		path++;
	}
	return (NULL);
}

void do_exec(char *cmd_path, char **cmd_str, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		printf("pipe error\n");
	pid = fork();
	if (pid == -1)
		printf("error\n");
	if (pid == 0)
	{
		close(fd[0]);
		execve(cmd_path, cmd_str, env);
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
}

void	pipe_in(char *cmd_path, char **cmd_str, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		printf("pipe error\n");
	pid = fork();
	if (pid == -1)
		printf("error\n");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(cmd_path, cmd_str, env);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	waitpid(pid, NULL, 0);
}

char	**make_env(t_data *data)
{
	int		len;
	t_list	*temp;
	char	**env;
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
		env[++idx] = strdup(temp->key);
		env[idx] = ft_strjoin_pipex(env[idx], "=");
		env[idx] = ft_strjoin_pipex(env[idx], temp->value);
		temp = temp->next;
	}
	return (env);
}

void	set_scmd(t_data *data, node *n)
{
	char	**cmd_str;
	char	*cmd_path;
	char	**env;

	cmd_str = ft_split(n->node_str, ' ');
	
	if (!strcmp(cmd_str[0], "echo"))
		ft_echo(cmd_str);
	else if (!strcmp(cmd_str[0], "cd"))
		ft_cd(cmd_str);
	else if (!strcmp(cmd_str[0], "pwd"))
		ft_pwd(cmd_str);
	else if (!strcmp(cmd_str[0], "export"))
		ft_export(cmd_str, data);
	else if (!strcmp(cmd_str[0], "unset"))
		ft_unset(cmd_str, data);
	else if (!strcmp(cmd_str[0], "env"))
		ft_env(cmd_str, data->env);
	else if (!strcmp(cmd_str[0], "exit"))
		ft_exit(cmd_str);
	else
	{
		cmd_path = check_path(data->env, cmd_str[0]);
		if (!cmd_path)
		{
			printf("cmd error\n");
			return ;
		}
		env = make_env(data);
		if (n->pipe < 1)
			do_exec(cmd_path, cmd_str, env);
		else
			pipe_in(cmd_path, cmd_str, env);
	}
}