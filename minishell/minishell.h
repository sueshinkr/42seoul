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

enum TYPE {WORD, PIPE, CMD, SCMD, RDIRS, RDIR};


typedef struct s_list
{
	char			*str;
	struct s_list	*next;
	// env 저장하는 리스트
} t_list;

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
void	init_tree(char *line, char **envp);
void	make_tree(char *str, node *n);
char	*set_text(char *str);
void	decode_text(char *str);

char*	str_cut_front(char *str, int idx);
char*	str_cut_back(char *str, int idx);
char	*ft_strjoin(char *str1, char *str2, int len);
char	**ft_split(char const *str, char c);

int		case_pipe(char *str, node *n, int idx);
int		case_cmd(char *str, node *n, int idx);
void	case_cmd_rdir(char *str, node *n, int idx);
void	case_rdir_cmd(char *str, node *n, int idx);
void	case_scmd(char *str, node *n);
int		case_rdir(char *str, node *n, int idx);

void	set_rdir(node *n);
void	set_scmd(t_data *data, node *n);

#endif