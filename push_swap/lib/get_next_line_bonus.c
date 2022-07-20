/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:59:46 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 20:16:53 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*check_remain(t_list_gnl *remain, int fd)
{
	char	*buff;
	char	*temp;
	int		read_idx;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!remain->str || !ft_strchr_gnl(remain->str, '\n'))
	{
		read_idx = read(fd, buff, BUFFER_SIZE);
		if (read_idx <= 0)
		{
			remain->flag = -1;
			break ;
		}
		buff[read_idx] = '\0';
		if (!remain->str)
			remain->str = ft_strdup_gnl(buff);
		else
		{	
			temp = ft_strjoin_gnl(remain->str, buff);
			remain->str = temp;
		}
	}
	free(buff);
	return (remain->str);
}

static char	*update_remain(char *remain_str)
{
	char	*new;
	char	*fix_remain_str;
	int		idx;
	int		len;

	idx = -1;
	if (!remain_str)
		return (NULL);
	fix_remain_str = ft_strchr_gnl(remain_str, '\n');
	if (!fix_remain_str || !(ft_strlen_gnl(fix_remain_str) - 1))
	{
		free(remain_str);
		return (NULL);
	}
	len = ft_strlen_gnl(++fix_remain_str);
	new = (char *)malloc((len + 1) * sizeof(char));
	while (len > ++idx && *(fix_remain_str + idx))
		*(new + idx) = *(fix_remain_str + idx);
	*(new + idx) = 0;
	free(remain_str);
	return (new);
}

static char	*check_free(t_list_gnl *rm, t_list_gnl **head)
{
	t_list_gnl	*temp;

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

static char	*make_next_line(char *str)
{
	char	*next_line;
	int		len;

	if (!str)
		return (NULL);
	len = 0;
	while (*(str + len))
	{
		if (*(str + len++) == '\n')
			break ;
	}
	next_line = (char *)malloc((len + 1) * sizeof(char));
	*(next_line + len) = '\0';
	while (--len >= 0)
		*(next_line + len) = *(str + len);
	free(str);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static t_list_gnl	*head;
	t_list_gnl			*remain;
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{	
		head = (t_list_gnl *)malloc(sizeof(t_list_gnl));
		head->next = NULL;
		head->fd = -1;
	}
	remain = add_fd_remain(head, fd);
	if (!check_remain(remain, fd))
		return (NULL);
	else
		next_line = make_next_line(ft_strdup_gnl(remain->str));
	remain->str = update_remain(remain->str);
	if (!remain->str)
		check_free(head, &head);
	return (next_line);
}
