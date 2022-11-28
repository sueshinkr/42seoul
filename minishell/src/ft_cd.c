#include "minishell.h"

int	ft_cd(char **argvs, t_data *data)
{
	char	*path;

	if (argvs[1] == 0)
	{
		path = get_env(strdup("HOME"), data->env);
		if (path == NULL)
		{
			errno = 1;
			write(2, "cd: HOME not set\n", strlen("cd: HOME not set\n"));
			return (1);
		}
	}
	else
		path = argvs[1];
	if (chdir(path) == -1)
	{
		free(path);
		perror(argvs[0]);
		return (errno);
	}
	free(path);
	return (0);
}
