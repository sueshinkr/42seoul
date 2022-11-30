#include "minishell.h"

int	ft_exit(char **argvs)
{
	ft_printf("exit\n");
	if (!argvs[1])
		exit(0);
	if (!is_numeric(argvs[1]))
	{
		write(2, "exit: numeric argument required\n", \
		ft_strlen("exit: numeric argument required\n"));
		return (1);
	}
	if (argvs[2])
	{
		write(2, "exit: too many arguments\n", \
		ft_strlen("exit: too many arguments\n"));
		return (1);
	}
	exit(ft_atoi(argvs[1]));
}
