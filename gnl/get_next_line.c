/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:26:14 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/21 11:34:54 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		else
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
	ft_strlcpy(next_line, remain, len + 1);
	return (next_line);
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
	static char	*remain = NULL;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remain = check_remain(fd, remain);
	if (!remain)
		return (NULL);
	next_line = make_next_line(remain);
	remain = update_remain(remain);
	return (next_line);
}

/*
1) remain??? ????????? ??????
2) ?????? ??????
	2-1) \n??? ??????????????????
		?????? 4)??? ??????
	2-2) \n??? ??????
		> read ??????
3) ?????? ?????? ?????? read???
4) new next line ??????
5) ???????????? remain??? ??????
6) ??????
*/
