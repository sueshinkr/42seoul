#include "minishell.h"

int	ft_cd(char **argvs)
{
	char	*path;

	if (argvs[1] == 0)
	{
		path = getenv("HOME");
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
		perror(argvs[0]);
		return (errno);
	}
	return (0);
}

static void	write_str(char **argvs, int mode)
{
	int	idx;

	if (mode == 1)
		idx = 1;
	else
		idx = 2;
	while (argvs[idx])
	{
		if (idx != mode)
			write(1, " ", 1);
		decode_text(argvs[idx]);
		write(1, argvs[idx], strlen(argvs[idx]));
		idx++;
	}
	if (mode == 1)
		write(1, "\n", 1);
}

int	ft_echo(char **argvs)
{
	if (strcmp(argvs[1], "-n") == 0)
		write_str(argvs, 2);
	else
		write_str(argvs, 1);
	return (0);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(char *key, char *val)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list) * 1);
	if (!lst)
		return (0);
	lst->key = key;
	lst->value = val;
	lst->next = NULL;
	return (lst);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		idx;
	char	*dest;

	idx = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (NULL);
	while (idx < len)
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	*find_key(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx] != '=')
		idx++;
	s[idx] = '\0';
	return (ft_strdup(s));
}

char	*find_val(char *s)
{
	int	idx;

	idx = 0;
	while (*s != '=')
		s++;
	return (ft_strdup(++s));
}

t_list	*ft_init_env(char **envp)
{
	int		idx;
	char	*key;
	char	*val;
	t_list	*node;
	t_list	*head;

	idx = 0;
	head = NULL;
	while (envp[idx])
	{
		key = find_key(envp[idx]);
		val = find_val(envp[idx]);
		node = ft_lstnew(key, val);
		ft_lstadd_front(&head, node);
		head = node;
		idx++;
	}
	return (head);
}

int	ft_env(char **argv, t_list *env)
{
	if (argv[1] != 0)
	{
		write(2, "No such file or directory\n", \
		strlen("No such file or directory\n"));
		return (127);
	}
	while (env)
	{
		if (env->value)
			printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
	return (0);
}

int	is_valid(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c == '_')
		return (1);
	return (0);
}


// value없이 key값만 넣는경우 고려해야할듯
int	ft_export(char **argvs, t_list *env)
{
	t_list	*node;
	int		idx;
	int		ret;

	idx = 1;
	ret = 0;
	if (!argvs[1])
	{
		while (env->key)
		{
			if (env->value)
				printf("declare -x %s=\"%s\"\n", env->key, env->value);
			else
				printf("declare -x %s\n", env->key);
			env = env->next;
		}
	}
	else
	{
		while (argvs[idx])
		{
			if (is_valid(argvs[idx][0]))
			{
				node = ft_lstnew(find_key(argvs[idx]), find_val(argvs[idx]));
				ft_lstadd_front(&env, node);
			}
			else
			{
				write(2, "unset: `", strlen("unset: `"));
				write(2, argvs[idx], strlen(argvs[idx]));
				write(2, "': not a valid identifier", \
				strlen("': not a valid identifier"));
				ret = 1;
			}
			idx++;
		}
	}
	return (ret);
}

void	ft_lstdel_value(t_list *lst, char *val)
{
	t_list	*prev;

	prev = NULL;
	while (lst && strncmp(lst->key, val, strlen(val) + 1))
	{
		prev = lst;
		lst = lst->next;
	}
	prev->next = lst->next;
	free(lst->key);
	free(lst->value);
	free(lst);
}

int	ft_unset(char **argv, t_list *env)
{
	int	idx;
	int	ret;

	idx = 1;
	ret = 0;
	while (argv[idx])
	{
		if (is_valid(argv[idx][0]))
			ft_lstdel_value(env, argv[idx]);
		else
		{
			write(2, "unset: `", strlen("unset: `"));
			write(2, argv[idx], strlen(argv[idx]));
			write(2, "': not a valid identifier", \
			strlen("': not a valid identifier"));
			ret = 1;
		}
		idx++;
	}
	return (ret);
}

int	ft_pwd(char **argvs)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		return (1);
	printf("%s\n", path);
	free(path);
	return (0);
}

int	is_numeric(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] >= '0' && s[idx] <= '9')
			;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	result;

	minus = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += ((*str) - '0') * minus;
		str++;
	}
	return (result);
}

int	ft_exit(char **argvs)
{
	printf("exit\n");
	if (!argvs[1])
		exit(0);
	if (!is_numeric(argvs[2]))
	{
		write(2, "exit: numeric argument required", \
		strlen("exit: numeric argument required"));
		return (1);
	}
	if (argvs[2])
	{
		write(2, "exit: too many arguments", \
		strlen("exit: too many arguments"));
		return (1);
	}
	exit(ft_atoi(argvs[1]));
}