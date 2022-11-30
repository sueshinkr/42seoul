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
