/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:08:50 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/10 22:18:05 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*add_fd_remain(t_list *remain, int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->str = NULL;
	new->fd = fd;
	new->next = NULL;
	new->flag = 1;
	while (remain)
	{
		if (remain->fd == fd)
		{
			free(new);
			break ;
		}
		if (!remain->next)
		{
			remain->next = new;
			return (new);
		}
		remain = remain->next;
	}
	return (remain);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	while (1)
	{
		if (*str == (char)c)
			return ((char *)str);
		else if (!*str)
			return (NULL);
		str++;
	}
}

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*result;

	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	result = str;
	while (*src)
		*str++ = *src++;
	*str = 0;
	return (result);
}

/*
char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*result;
	char	*joinstr;
	int		joinstr_len;

	joinstr_len = ft_strlen(str1) + ft_strlen(str2);
	joinstr = (char *)malloc((joinstr_len + 1) * sizeof(char));
	result = joinstr;
	if (!joinstr)
		return (NULL);
	while (joinstr_len-- > 0)
	{
		if (*str1)
			*joinstr = *str1++;
		else if (*str2)
			*joinstr = *str2++;
		joinstr++;
	}
	*joinstr = 0;
	return (result);
}
*/

char	*ft_strjoin(char *str1, char *str2)
{
	char	*joinstr;
	size_t	joinstr_len;
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	idx2 = 0;
	joinstr_len = ft_strlen(str1) + ft_strlen(str2) + 1;
	joinstr = (char *)malloc(joinstr_len * sizeof(char));
	if (!joinstr)
		return (NULL);
	while (*(str1 + idx1))
	{
		*(joinstr + idx1) = *(str1 + idx1);
		idx1++;
	}
	while (*(str2 + idx2))
	{
		*(joinstr + idx1 + idx2) = *(str2 + idx2);
		idx2++;
	}
	*(joinstr + idx1 + idx2) = 0;
	free(str1);
	return (joinstr);
}
