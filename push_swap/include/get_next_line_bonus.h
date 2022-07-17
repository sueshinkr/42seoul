/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:35:40 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/17 19:29:45 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# define BUFFER_SIZE 1

typedef struct s_list_gnl
{
	char				*str;
	int					fd;
	int					flag;
	struct s_list_gnl	*next;
}	t_list_gnl;

char		*get_next_line(int fd);
t_list_gnl	*add_fd_remain(t_list_gnl *remain, int fd);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char *str1, char *str2);

#endif
