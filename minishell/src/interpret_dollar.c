/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:20 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:57:19 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	*interpret_dollar_only(char *ret, int *idx)
{
	ret = ft_strjoin_len(ret, "$", 1);
	(*idx)--;
	return (ret);
}

char	*interpret_dollar(char *str, char *ret, int *idx, t_data *data)
{
	char	*temp;

	if (!str[++(*idx)] || (str[*idx - 2] == '\"' && \
		(str[*idx] == '\'' || str[*idx] == '\"')) || str[(*idx)] == ' ')
		ret = interpret_dollar_only(ret, idx);
	else if (str[*idx - 2] != '\"' && str[*idx] == '\'')
		ret = interpret_smallquotes(str, ret, idx);
	else if (str[*idx - 2] != '\"' && str[*idx] == '\"')
		ret = interpret_bigquotes(str, ret, idx, data);
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
