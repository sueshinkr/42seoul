/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:03:14 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/05 15:26:49 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	no_input_export(t_list *env)
{
	while (env && env->key)
	{
		if (env->value)
			ft_printf("declare -x %s=\"%s\"\n", env->key, env->value);
		else
			ft_printf("declare -x %s\n", env->key);
		env = env->next;
	}
}

static int	exist_export(t_list *temp, char *temp_key, char *temp_val)
{
	if (!ft_strcmp(temp_key, temp->key))
	{
		if (!temp_val && (ft_strlen(temp->value) == 0))
			temp->value = ft_strdup("");
		else if (!temp_val)
			;
		else
		{
			free(temp->value);
			temp->value = temp_val;
		}
		free(temp_key);
		return (1);
	}
	return (0);
}

static void	valid_export(char *str, t_data *data)
{
	int		idx;
	t_list	*temp;
	char	*temp_key;
	char	*temp_val;

	idx = 0;
	while (str[idx] && str[idx] != '=')
		idx++;
	temp_key = str_cut_front(str, idx + 1);
	if (!str[idx])
		temp_val = NULL;
	else
		temp_val = str_cut_back(str, idx);
	temp = data->env;
	while (temp->key)
	{
		if (exist_export(temp, temp_key, temp_val))
			return ;
		temp = temp->next;
	}
	ft_lstadd_front(&data->env, ft_lstnew(temp_key, temp_val));
}

static void	invalid_export(char *str)
{
	write(2, "export: `", ft_strlen("export: `"));
	write(2, str, ft_strlen(str));
	write(2, "': not a valid identifier\n", \
	ft_strlen("': not a valid identifier\n"));
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
