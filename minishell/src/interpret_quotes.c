/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:23 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:53 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			ret = ft_strjoin_len(ret, &str[*idx], 1);
		}
	}
	else
		ret = ft_strjoin_len(ret, &str[*idx], 1);
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
			else if (str[*idx] == '|')
				str[*idx] = -2;
			if (str[*idx] == '$')
				ret = interpret_dollar(str, ret, idx, data);
			else
				ret = ft_strjoin_len(ret, &str[*idx], 1);
		}
	}
	else
		ret = ft_strjoin_len(ret, &str[*idx], 1);
	return (ret);
}
