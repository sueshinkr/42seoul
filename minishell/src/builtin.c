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
	if (!argvs[1])
		write(1, "\n", 1);
	else if (strcmp(argvs[1], "-n") == 0)
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

	return (str_cut_front(s, idx));
	s[idx] = '\0';
	return (ft_strdup(s));
}

char	*find_val(char *s)
{
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
	while (env->key)
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

void	no_input_export(t_list *env)
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

void	valid_export(char *str, t_data *data)
{
	int		idx;
	t_list	*temp;
	char	*temp_key;
	char	*temp_val;

	idx = 0;
	while (str[idx] != '=')
		idx++;
	temp_key = str_cut_front(str, idx + 1);
	temp_val = str_cut_back(str, idx);
	temp = data->env;
	while (temp->key)
	{
		if (!strcmp(temp_key, temp->key))
		{
			free(temp_key);
			free(temp->value);
			temp->value = temp_val;
			return ;
		}	
		temp = temp->next;
	}
	ft_lstadd_front(&data->env, ft_lstnew(temp_key, temp_val));
}

void	invalid_export(char *str)
{
	write(2, "export: `", strlen("export: `"));
	write(2, str, strlen(str));
	write(2, "': not a valid identifier\n", \
	strlen("': not a valid identifier\n"));
}

int	ft_export(char **argvs, t_data *data)
{
	int		idx;
	int		ret;

	idx = 1;
	ret = 0;
	if (!argvs[1])
		no_input_export(data->env);
	else
	{
		while (argvs[idx])
		{
			decode_text(argvs[idx]);
			if (is_valid(argvs[idx][0]))
				valid_export(argvs[idx], data);
			else
			{
				invalid_export(argvs[idx]);
				ret = 1;
			}
			idx++;
		}
	}
	return (ret);
}

void	ft_lstdel_value(t_list *lst, char *val)
{
	t_list	*temp;

	while (lst->next->key)
	{
		if (!strcmp(lst->next->key, val))
		{
			temp = lst->next;
			lst->next = lst->next->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			return ;
		}
		else
			lst = lst->next;
	}
}

int	ft_unset(char **argv, t_data *data)
{
	int	idx;
	int	ret;
	t_list	*temp;

	idx = 1;
	ret = 0;
	if(!argv[idx])
		return (ret);
	while (argv[idx])
	{
		decode_text(argv[idx]);
		if (is_valid(argv[idx][0]))
		{
			// 맨 처음 환경변수 삭제
			if (!strcmp(data->env->key, argv[idx]))
			{
				temp = data->env;
				data->env = data->env->next;
				free(temp->key);
				free(temp->value);
				free(temp);
			}
			else
				ft_lstdel_value(data->env, argv[idx]);
		}
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
	(void)argvs;
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
		idx++;
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
	
	if (!is_numeric(argvs[1]))
	{
		write(2, "exit: numeric argument required\n", \
		strlen("exit: numeric argument required\n"));
		return (1);
	}

	if (argvs[2])
	{
		write(2, "exit: too many arguments\n", \
		strlen("exit: too many arguments\n"));
		return (1);
	}
	exit(ft_atoi(argvs[1]));
}