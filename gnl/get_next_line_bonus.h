/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:35:40 by sueshin           #+#    #+#             */
/*   Updated: 2022/04/21 11:23:54 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	int				fd;
	int				flag;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*add_fd_remain(t_list *remain, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *str1, char const *str2);

#endif
