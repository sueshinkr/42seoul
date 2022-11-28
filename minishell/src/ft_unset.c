#include "minishell.h"

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

static void	valid_unset(char *str, t_data *data)
{
	t_list	*temp;

	if (!strcmp(data->env->key, str))
	{
		temp = data->env;
		data->env = data->env->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
	else
		ft_lstdel_value(data->env, str);
}

static void	invalid_unset(char *str)
{
	write(2, "unset: `", strlen("unset: `"));
	write(2, str, strlen(str));
	write(2, "': not a valid identifier", \
	strlen("': not a valid identifier"));
}

int	ft_unset(char **argv, t_data *data)
{
	int		idx;
	int		ret;

	idx = 1;
	ret = 0;
	if (!argv[idx])
		return (ret);
	while (argv[idx])
	{
		decode_text(argv[idx]);
		if (is_valid(argv[idx][0]))
			valid_unset(argv[idx], data);
		else
		{
			invalid_unset(argv[idx]);
			ret = 1;
		}
		idx++;
	}
	return (ret);
}
