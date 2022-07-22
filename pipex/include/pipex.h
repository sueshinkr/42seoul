/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:21 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/22 12:36:20 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line_bonus.h"

char	**ft_split(char const *str, char c);
char	*ft_strjoin_pipex(char *str1, char *str2);

void	check_file(char *argv);
char	**find_enpath(char **envp);
char	*check_path(char **path, char *cmd);

#endif
