/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:21 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/22 17:22:20 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line_bonus.h"

typedef struct s_list
{
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*path_cmd1;
	char	*path_cmd2;
}	t_list;

void	read_arg(char **argv, char **envp, t_list *arg);

char	**ft_split(char const *str, char c);
char	*ft_strjoin_pipex(char *str1, char *str2);

void	check_file(char *argv);
char	**find_enpath(char **envp);
char	*check_path(char **path, char *cmd);
void	open_outfile(char *outfile);

void	print_error(int num);

#endif
