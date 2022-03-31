/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:32:01 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/31 22:02:29 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_next_line(char **remain_str, char *next_line, int fd)
{	
	int	len;

	len = 0;
	while (**remain_str)
	{
		if (**remain_str == '\n')
		{
			next_line = make_next_line(*remain_str - len, len);
			(*remain_str)++;
			return (next_line);
		}
		len++;
		(*remain_str)++;
	}
	(*remain_str) -= len;
	return (NULL);
}

char	*make_next_line(char *buff, int len)
{
	char	*next_line;
	
	next_line = (char *)malloc((len + 1) * sizeof(char));
	while (*buff != '\n' && *buff)
		*next_line++ = *buff++;
	*next_line = '\0';
	return (next_line - len);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*remain_str[FOPEN_MAX];
	char		*next_line;

	if (!remain_str[fd])
	{
		read(fd, buff, BUFFER_SIZE);
		remain_str[fd] = ft_strdup(buff);
	}
	while (1)
	{
		next_line = check_next_line(&remain_str[fd], next_line, fd);
		if (next_line)
			break;
		else
		{
			read(fd, buff, BUFFER_SIZE);
			remain_str[fd] = ft_strjoin(remain_str[fd], buff);
		}
	}
	return (next_line);
}
