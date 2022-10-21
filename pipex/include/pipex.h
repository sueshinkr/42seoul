/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:21 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/10 20:47:12 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
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
	int		is_here;
	int		is_error;
}	t_arg;

void	read_arg(int num, char **argv, char **envp, t_arg *arg);
int		open_infile(char *infile, t_arg *arg);
int		open_outfile(char *outfile, t_arg *arg);
int		open_outfile_here(char *outfile, t_arg *arg);

void	dup_check(int to, int from, t_arg *arg);
int		check_file(char *argv);
char	**find_enpath(char **envp);
char	*check_path(char **path, char *cmd);
int		open_outfile(char *outfile, t_arg *arg);
int		open_outfile_here(char *outfile, t_arg *arg);

void	pipe_in(t_arg *arg, int idx, int fdin);
void	pipe_in_last(t_arg *arg, int idx);
void	pipe_last(t_arg *arg, int idx, int fdin, int fdout);

void	free_all(t_arg *arg);
void	print_error(int num, t_arg *arg);

char	**ft_split(char const *str, char c);
char	*ft_strjoin_pipex(char *str1, char *str2);

#endif
