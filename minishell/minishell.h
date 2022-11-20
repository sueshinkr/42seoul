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

typedef struct Node
{
	enum TYPE type;
	struct Node *left;
	struct Node *right;
	char *node_str;

	int level;
} node;

void	init_tree(char *line);
void	make_tree(char *str, node *n);
char	*set_text(char *str);
void	decode_text(char *str);

char*	str_cut_front(char *str, int idx);
char*	str_cut_back(char *str, int idx);
char	*ft_strjoin(char *str1, char *str2, int len);

int		case_pipe(char *str, node *n, int idx);
int		case_cmd(char *str, node *n, int idx);
void	case_cmd_rdir(char *str, node *n, int idx);
void	case_rdir_cmd(char *str, node *n, int idx);
void	case_scmd(char *str, node *n, int idx);
int		case_rdir(char *str, node *n, int idx);

#endif