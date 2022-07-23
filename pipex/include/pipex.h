/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:21 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/23 23:33:32 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "ft_printf.h"
# include "get_next_line_bonus.h"

typedef struct s_cmd
{
	char	**cmd_str;
	char	*cmd_path;
}	t_cmd;

typedef struct s_arg
{
	char	**path;
	t_cmd	**cmd;
	char	**envp;
	int		cmd_num;
}	t_arg;

void	read_arg(int num, char **argv, char **envp, t_arg *arg);

char	**ft_split(char const *str, char c);
char	*ft_strjoin_pipex(char *str1, char *str2);

void	check_file(char *argv, t_arg *arg);
char	**find_enpath(char **envp);
char	*check_path(char **path, char *cmd);
void	open_outfile(char *outfile, t_arg *arg);

void	print_error(int num, t_arg *arg);

#endif
