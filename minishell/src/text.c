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

char	*check_env(char *str)
{
	char	*temp;

	temp = strdup("");
	while (*str && !strchr(" \"\'", *str))
		temp = ft_strjoin(temp, str++, 1);
	return (getenv(temp));
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

char	*interpret_dollar(char *str, char *ret, int *idx)
{
	char	*temp;

	temp = check_env(&str[*idx + 1]);
	if (!temp)
	{
		while (str[++(*idx)] && !strchr(" \"\'", str[*idx]))
			;
		return (ret);
	}
	ret = ft_strjoin(ret, temp, strlen(temp));
	while (str[++(*idx)] && !strchr(" \"\'", str[*idx]))
		;
	(*idx)--;
	return (ret);
}

char	*interpret_bigquotes(char *str, char *ret, int *idx)
{
	if (check_bigquotes(&str[*idx + 1]))
	{
		while (str[++(*idx)] && str[*idx] != '\"')
		{
			if (str[*idx] == ' ')
				str[*idx] = -1;
			if (str[*idx] == '$')
				ret = interpret_dollar(str, ret, idx);
			else
				ret = ft_strjoin(ret, &str[*idx], 1);
		}
	}
	else
		ret = ft_strjoin(ret, &str[*idx], 1);
	return (ret);
}

char	*set_text(char *str)
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
			ret = interpret_bigquotes(str, ret, &idx);
		else if (str[idx] == '$')
			ret = interpret_dollar(str, ret, &idx);
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
