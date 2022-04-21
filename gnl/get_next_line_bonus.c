/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:59:46 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/17 13:12:15 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*check_free(t_list *rm, t_list **head)
{
	t_list	*temp;

	while (rm)
	{
		if (!rm->next)
			break ;
		if (!(rm->next)->str && !(rm->next)->next && (rm->next)->flag == -1)
		{
			free(rm->next);
			rm->next = NULL;
		}
		else if (!(rm->next)->str && (rm->next)->next && (rm->next)->flag == -1)
		{
			temp = rm->next;
			rm->next = (rm->next)->next;
			free(temp);
		}
		rm = rm->next;
	}
	if (!(*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	return (NULL);
}

static char	*check_remain(int fd, t_list *remain)
{
	char	*buff;
	char	*temp;
	int		read_idx;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!remain->str || !ft_strchr(remain->str, '\n'))
	{
		read_idx = read(fd, buff, BUFFER_SIZE);
		if (read_idx <= 0)
		{
			remain->flag = -1;
			break ;
		}
		buff[read_idx] = '\0';
		if (!remain->str)
			remain->str = ft_strdup(buff);
		else if (!ft_strchr(remain->str, '\n'))
		{	
			temp = ft_strjoin(remain->str, buff);
			free(remain->str);
			remain->str = temp;
		}
	}
	free(buff);
	return (remain->str);
}

static char	*make_next_line(char *remain)
{
	char	*next_line;
	int		len;

	if (!remain)
		return (NULL);
	len = 0;
	while (*(remain + len))
	{
		if (*(remain + len++) == '\n')
			break ;
	}
	next_line = (char *)malloc((len + 1) * sizeof(char));
	while (*remain)
	{
		*next_line++ = *remain;
		if (*remain++ == '\n')
			break ;
	}
	*next_line = '\0';
	free(remain - len);
	return (next_line - len);
}

static char	*update_remain(char *remain)
{
	char	*temp;
	char	*fix_remain;
	size_t	idx;

	idx = -1;
	if (!remain)
		return (NULL);
	fix_remain = ft_strchr(remain, '\n');
	if (!fix_remain || !(ft_strlen(fix_remain) - 1))
	{
		free(remain);
		return (NULL);
	}
	temp = (char *)malloc(ft_strlen(fix_remain++) * sizeof(char));
	while (ft_strlen(fix_remain) > ++idx && *(fix_remain + idx))
		*(temp + idx) = *(fix_remain + idx);
	*(temp + idx) = 0;
	free(remain);
	return (temp);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*remain;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{	
		head = (t_list *)malloc(sizeof(t_list));
		head->next = NULL;
		head->fd = -1;
	}
	if (!head->next)
		remain = add_fd_remain(head, fd);
	else
		remain = add_fd_remain(head->next, fd);
	next_line = check_remain(fd, remain);
	if (next_line)
		next_line = ft_strdup(next_line);
	remain->str = update_remain(remain->str);
	if (!remain->str)
		check_free(head, &head);
	return (make_next_line(next_line));
}
