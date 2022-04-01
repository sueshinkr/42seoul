/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:32:01 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/01 14:14:02 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_next_line(char **remain_str, char *next_line)
{	
	int		len;
	char	*temp;

	len = 0;
	while (**remain_str)
	{
		len++;
		(*remain_str)++;
		if (**remain_str == '\n')
		{
			next_line = make_next_line(*remain_str - len + 1, len);
			temp = ft_strdup(*remain_str);
			free(*remain_str - len);
			*remain_str = temp;
			return (next_line);
		}
	}
	(*remain_str) -= len;
	return (NULL);
}

char	*make_next_line(char *buff, int len)
{
	char	*next_line;
	
	next_line = (char *)malloc((len + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	while (*buff != '\n' && *buff)
		*next_line++  = *buff++;
	*next_line++ = *buff++;
	*next_line = '\0';
	return (next_line - len);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*remain_str[FOPEN_MAX];
	char		*next_line;
	int			read_idx;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remain_str[fd])
	{
		read_idx = read(fd, buff, BUFFER_SIZE);
		buff[read_idx] = '\0';
		remain_str[fd] = ft_strdup(buff);
		if (!remain_str[fd])
			return (NULL);
	}
	while (1)
	{
		next_line = check_next_line(&remain_str[fd], next_line);
		if (next_line)
			break;
		else
		{
			read_idx = read(fd, buff, BUFFER_SIZE);
			buff[read_idx] = '\0';
			if (!ft_strlen(buff))
				return (NULL);
			next_line = ft_strjoin(remain_str[fd], buff);
			free(remain_str[fd]);
			remain_str[fd] = next_line;
		}
	}
	return (next_line);
}
