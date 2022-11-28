#include "minishell.h"

int	check_smallquotes(char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
	{
		if (str[idx] == '\'')
			return (1);
	}
	return (0);
}

int	check_bigquotes(char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
	{
		if (str[idx] == '\"')
			return (1);
	}
	return (0);
}

char	*interpret_smallquotes(char *str, char *ret, int *idx)
{
	if (check_smallquotes(&str[*idx + 1]))
	{
		while (str[++(*idx)] != '\'')
		{
			if (str[*idx] == ' ')
				str[*idx] = -1;
			ret = ft_strjoin(ret, &str[*idx], 1);
		}
	}
	else
		ret = ft_strjoin(ret, &str[*idx], 1);
	return (ret);
}

char	*interpret_dollar(char *str, char *ret, int *idx, t_data *data)
{
	char	*temp;

	if (!str[++(*idx)] || (str[*idx - 2] == '\"' && str[*idx] == '\"'))
		ret = ft_strjoin(ret, "$", 1);
	else if (str[(*idx)] == ' ')
	{
		ret = ft_strjoin(ret, "$", 1);
		(*idx)--;
	}
	else if (str[(*idx)] == '\"' || str[(*idx)] == '\'')
		(*idx)--;
	else
	{
		if (str[(*idx)] && !is_valid(str[*idx]))
			(*str)++;
		else
		{
			temp = check_env(&str[(*idx)], idx, data);
			if (!temp)
				return (ret);
			ret = ft_strjoin(ret, temp, strlen(temp));
		}
	}
	return (ret);
}

char	*interpret_bigquotes(char *str, char *ret, int *idx, t_data *data)
{
	if (check_bigquotes(&str[*idx + 1]))
	{
		while (str[++(*idx)] && str[*idx] != '\"')
		{
			if (str[*idx] == ' ')
				str[*idx] = -1;
			if (str[*idx] == '$')
				ret = interpret_dollar(str, ret, idx, data);
			else
				ret = ft_strjoin(ret, &str[*idx], 1);
		}
	}
	else
		ret = ft_strjoin(ret, &str[*idx], 1);
	return (ret);
}
