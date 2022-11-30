#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdlib.h>
# include <printf.h>
# include <unistd.h>
# include <fcntl.h>

# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <errno.h>

# include "ft_printf.h"
# include "get_next_line_bonus.h"

enum TYPE {WORD, PIPE, CMD, SCMD, RDIRS, RDIR};

typedef struct s_list
{
	char			*key;
	char			*value;
	struct s_list	*next;
}	t_list;

typedef struct s_node
{
	enum TYPE	type;
	struct s_node	*left;
	struct s_node	*right;
	char	*node_str;
} t_node;

typedef struct s_data
{
	t_node	*head;
	t_list	*env;
	pid_t	pid;
	int		outfile_fd;
	int		infile_fd;
	int		stdout_fd;
	int		stdin_fd;
	int		last_pipe[2];
	int		pipe_num;
	int		cmd_cnt;
	int		exit_code;
	int		err_flag;
} t_data;

t_node	*init_node(void);
void	init_tree(char *line, t_data *data);
void	make_tree(t_data *data, char *str, t_node *n);
void	search_tree(t_data *data, t_node *n);
void	free_tree(t_data *data, t_node *n);
char	*parse_line(char *str, t_data *data);
char	*get_env(char *str, t_list *env);
void	decode_text(char *str);

char	*get_env(char *str, t_list *env);
char	*check_env(char *str, int *idx, t_data *data);
int		check_smallquotes(char *str);
int		check_bigquotes(char *str);
char	*interpret_smallquotes(char *str, char *ret, int *idx);
char	*interpret_bigquotes(char *str, char *ret, int *idx, t_data *data);
char	*interpret_dollar(char *str, char *ret, int *idx, t_data *data);

char*	str_cut_front(char *str, int idx);
char*	str_cut_back(char *str, int idx);
char	*ft_strjoin_len(char *str1, char *str2, int len);
char	*ft_strjoin_nofree(char *str1, char *str2);
int		ft_strcmp(const char *str1, const char *str2);
char	**ft_split(char const *str, char c);
int		is_numeric(char *s);
int		ft_atoi(const char *str);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *key, char *val);
void	free_arr(char **arr);

int		case_pipe(t_data *data, char *str, t_node *n, int idx);
int		case_cmd(t_data *data, char *str, t_node *n, int idx);
int		case_rdir(t_data *data, char *str, t_node *n, int idx);
void	case_rdir_cmd(t_data *data, char *str, t_node *n, int idx);

int		r_heredoc(t_data *data, char *delimeter);
void	set_rdir(t_data *data, t_node *n);

void	prt_execute_err(t_data *data);
int		is_builtin(t_data *data, char **cmd_str);
char	*check_path(t_list *env, t_data *data, char *cmd);
char	*ret_path(t_data *data, char **path, char *cmd);
void	pipe_cmd(t_data *data, char **cmd_str, char **env);
void	set_scmd(t_data *data, t_node *n);

int	ft_cd(char **argvs, t_data *data);
int	ft_echo(char **argvs);
int	ft_env(char **argv, t_list *env);
int	ft_export(char **argvs, t_data *data);
int	ft_unset(char **argv, t_data *data);
int	ft_pwd(char **argvs);
int	ft_exit(char **argvs);
int	is_valid(char c);

#endif