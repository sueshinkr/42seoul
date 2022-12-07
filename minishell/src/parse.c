/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:29 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:55 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *str, t_list *env)
{
	while (env && env->key)
	{
		if (!ft_strcmp(str, env->key))
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (NULL);
}

char	*check_env(char *str, int *idx, t_data *data)
{
	char	*temp;
	char	*ret;

	temp = ft_strdup("");
	while (*str && is_valid(*str))
	{
		temp = ft_strjoin_len(temp, str++, 1);
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
	ret = ft_strdup("");
	while (str[++idx])
	{
		if (str[idx] == '\'')
			ret = interpret_smallquotes(str, ret, &idx);
		else if (str[idx] == '\"')
			ret = interpret_bigquotes(str, ret, &idx, data);
		else if (str[idx] == '$')
			ret = interpret_dollar(str, ret, &idx, data);
		else if (str[idx] == '\t')
			;
		else
			ret = ft_strjoin_len(ret, &str[idx], 1);
	}
	return (ret);
}

void	decode_text(char *str)
{
	while (*str)
	{
		if (*str == -1)
			*str = ' ';
		else if (*str == -2)
			*str = '|';
		str++;
	}
}
