/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:59:46 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/11 23:30:48 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*add_fd_remain(int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->str = NULL;
	new->fd = fd;
	new->next = NULL;
	return (new);
}

static char	*check_remain(int fd, char *remain)
{
	char	*buff;
	char	*temp;
	int		read_idx;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!remain || !ft_strchr(remain, '\n'))
	{
		read_idx = read(fd, buff, BUFFER_SIZE);
		if (read_idx <= 0)
			break ;
		buff[read_idx] = '\0';
		if (!remain)
			remain = ft_strdup(buff);
		else if (!ft_strchr(remain, '\n'))
		{	
			temp = ft_strjoin(remain, buff);
			free(remain);
			remain = temp;
		}
	}
	free(buff);
	return (remain);
}

static char	*make_next_line(char *remain)
{
	char	*next_line;
	int		len;

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
	return (next_line - len);
}

static char	*update_remain(char *remain)
{
	char	*temp;
	char	*fix_remain;

	fix_remain = ft_strchr(remain, '\n');
	if (!fix_remain)
	{
		free(remain);
		return (NULL);
	}
	temp = (char *)malloc(ft_strlen(fix_remain) * sizeof(char));
	if (!ft_strlcpy(temp, fix_remain + 1, ft_strlen(fix_remain)))
	{
		free(temp);
		free(remain);
		return (NULL);
	}
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
		printf("start\n");
		head = (t_list *)malloc(sizeof(t_list));
		head->next = NULL;
	}
	if (head->next == NULL)
	{
		remain = add_fd_remain(fd);
		head->next = remain;
	}
	else
	{
		remain = head->next;
		while (remain)
		{
			if (remain->fd == fd)
				break;
			if (!remain->next)
				remain->next = add_fd_remain(fd);
			remain = remain->next;
		}
	}
	remain->str = check_remain(fd, remain->str);
	if (!remain->str)
		return (NULL);
	next_line = make_next_line(remain->str);
	remain->str = update_remain(remain->str);
	return (next_line);
}


/*
char	*get_next_line(int fd)
{
	static t_list	*remain;
	t_list			*head;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remain)
	{
		while (remain->next != head)
		{
			if (remain->fd == fd)
				break;
			if (remain->next == NULL)
				remain->next = add_fd_remain(fd);
			remain = remain->next;
		}
	}
	else
	{
		remain = add_fd_remain(fd);
		head->next = remain;
	}
	remain->str = check_remain(fd, remain->str);
	if (!remain->str)
		return (NULL);
	next_line = make_next_line(remain->str);
	remain->str = update_remain(remain->str);
	return (next_line);
}
*/

/*
원형 연결 리스트로 구현하기.
*/
