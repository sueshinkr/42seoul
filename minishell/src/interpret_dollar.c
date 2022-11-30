#include "minishell.h"

static char	*interprete_dollar_exit(char *ret, t_data *data)
{
	char	*temp;

	if (data->exit_code < 0)
		ret = ft_strjoin_len(ret, "-", 1);
	temp = ft_itoa(data->exit_code, 0);
	ret = ft_strjoin_len(ret, temp, ft_strlen(temp));
	free(temp);
	return (ret);
}

char	*interpret_dollar(char *str, char *ret, int *idx, t_data *data)
{
	char	*temp;

	if (!str[++(*idx)] || str[*idx] == '\'' \
		|| str[*idx] == '\"' || str[(*idx)] == ' ')
	{
		ret = ft_strjoin_len(ret, "$", 1);
		(*idx)--;
	}
	else if (str[(*idx)] == '?')
		ret = interprete_dollar_exit(ret, data);
	else
	{
		if (str[(*idx)] && !is_valid(str[*idx]))
			(*str)++;
		else
		{
			temp = check_env(&str[(*idx)], idx, data);
			if (!temp)
				return (ret);
			ret = ft_strjoin_len(ret, temp, ft_strlen(temp));
			free(temp);
		}
	}
	return (ret);
}
