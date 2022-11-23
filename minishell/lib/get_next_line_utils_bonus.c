/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:08:50 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 20:17:35 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list_gnl	*add_fd_remain(t_list_gnl *remain, int fd)
{
	t_list_gnl	*new;

	new = (t_list_gnl *)malloc(sizeof(t_list_gnl));
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

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strchr_gnl(const char *str, int c)
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

char	*ft_strdup_gnl(const char *src)
{
	char	*str;
	char	*result;

	str = (char *)malloc((ft_strlen_gnl(src) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	result = str;
	while (*src)
		*str++ = *src++;
	*str = 0;
	return (result);
}

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	char	*joinstr;
	size_t	joinstr_len;
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	idx2 = 0;
	joinstr_len = ft_strlen_gnl(str1) + ft_strlen_gnl(str2) + 1;
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
