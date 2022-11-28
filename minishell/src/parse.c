#include "minishell.h"

char	*get_env(char *str, t_list *env)
{
	while (env->key)
	{
		if (!strcmp(str, env->key))
			return (strdup(env->value));
		env = env->next;
	}
	return (NULL);
}

char	*check_env(char *str, int *idx, t_data *data)
{
	char	*temp;
	char	*ret;

	temp = strdup("");
	while (*str && is_valid(*str))
	{
		temp = ft_strjoin(temp, str++, 1);
		(*idx)++;
	}
	(*idx)--;
	ret = get_env(temp, data->env);
	free(temp);
	return (ret);
}

char	*parse_line(char *str, t_data *data)
{
	int		idx;
	char	*ret;

	idx = -1;
	ret = strdup("");
	while (str[++idx])
	{
		if (str[idx] == '\'')
			ret = interpret_smallquotes(str, ret, &idx);
		else if (str[idx] == '\"')
			ret = interpret_bigquotes(str, ret, &idx, data);
		else if (str[idx] == '$')
			ret = interpret_dollar(str, ret, &idx, data);
		else
			ret = ft_strjoin(ret, &str[idx], 1);
	}
	return (ret);
}

void	decode_text(char *str)
{
	while (*str)
	{
		if (*str == -1)
			*str = ' ';
		str++;
	}
}
