#include "minishell.h"

int	ft_env(char **argv, t_list *env)
{
	if (argv[1] != 0)
	{
		write(2, "No such file or directory\n", \
		ft_strlen("No such file or directory\n"));
		return (127);
	}
	while (env && env->key)
	{
		if (env->value)
			ft_printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (0);
}
