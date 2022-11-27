#ifndef MINISHELL_H
#define MINISHELL_H

#include <string.h>
#include <stdlib.h>
#include <printf.h>
#include <unistd.h>
#include <fcntl.h>

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>
#include <errno.h>

enum TYPE {WORD, PIPE, CMD, SCMD, RDIRS, RDIR};

typedef struct s_list
{
	char			*key;
	char			*value;
	struct s_list	*next;
}	t_list;

typedef struct Node
{
	enum TYPE	type;
	struct Node	*left;
	struct Node	*right;
	char	*node_str;
	int		pipe;
	int level;
} node;

typedef struct s_data
{
	node	*head;
	t_list	*env;
	int		outfile_fd;
	int		infile_fd;
	int		stdout_fd;
	int		stdin_fd;
	int		last_pipe[2];
	int		pipe_num;
} t_data;

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
size_t		ft_strlen_gnl(const char *str);
char		*ft_strchr_gnl(const char *str, int c);
char		*ft_strdup_gnl(const char *src);
char		*ft_strjoin_gnl(char *str1, char *str2);

node	*init_node(node *n);
void	init_tree(char *line, t_data *data);
void	make_tree(t_data *data, char *str, node *n);
char	*set_text(char *str, t_data *data);
char	*get_env(char *str, t_list *env);
void	decode_text(char *str);

char*	str_cut_front(char *str, int idx);
char*	str_cut_back(char *str, int idx);
char	*ft_strjoin(char *str1, char *str2, int len);
char	**ft_split(char const *str, char c);

int		case_pipe(t_data *data, char *str, node *n, int idx);
int		case_cmd(t_data *data, char *str, node *n, int idx);
void	case_cmd_rdir(t_data *data, char *str, node *n, int idx);
void	case_rdir_cmd(t_data *data, char *str, node *n, int idx);
int		case_rdir(t_data *data, char *str, node *n, int idx);
void	case_scmd(char *str, node *n);

void	set_rdir(t_data *data, node *n);
void	set_scmd(t_data *data, node *n);

int	ft_cd(char **argvs, t_data *data);
int	ft_echo(char **argvs);
int	ft_env(char **argv, t_list *env);
int	ft_export(char **argvs, t_data *data);
int	ft_unset(char **argv, t_data *data);
int	ft_pwd(char **argvs);
int	ft_exit(char **argvs);
int	is_valid(char c);

#endif