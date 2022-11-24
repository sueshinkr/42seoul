#include "minishell.h"

// 우선 전체 문자열에서 따옴표 벗겨내는 작업 실행
// 따옴표 내 공백은 -1로 바꿔두고, 최후에 다시 공백으로 전환
// 큰따옴표 내 환경변수도 이때 바꿔두기

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

char	*get_env(char *str, t_list *env)
{
	while (env->key)
	{
		if (!strcmp(str, env->key))
		{
			free(str);
			return (strdup(env->value));
		}
		env = env->next;
	}
	free(str);
	return (NULL);
}

char	*check_env(char *str, int *idx, t_data *data)
{
	char	*temp;

	temp = strdup("");
	while (*str && is_valid(*str))
	{
		temp = ft_strjoin(temp, str++, 1);
		(*idx)++;
	}
	(*idx)--;
	temp = get_env(temp, data->env);
	return (temp);
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

	//시작이 공백
	if (str[++(*idx)] && str[*idx] == ' ')
	{
		while (str[(*idx)] && str[*idx] == ' ')
			(*idx)++;
		str[--(*idx)] = -1;
		(*idx)--;
		return (ret);
	}
	//시작이 따옴표
	else if (str[(*idx)] == '\"' || str[(*idx)] == '\'')
	{
		(*idx)--;
		return (ret);
	}
	//시작이 not_valid한 문자
	//시작이 valid한 문자
	if (str[(*idx)] && !is_valid(str[*idx]))
	{
		(*str)++;
		return (ret);
	}
	temp = check_env(&str[(*idx)], idx, data);
	if (!temp)
		return (ret);
	ret = ft_strjoin(ret, temp, strlen(temp));
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

char	*set_text(char *str, t_data *data)
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
