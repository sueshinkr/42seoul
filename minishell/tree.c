#include "minishell.h"

char *arr[] = {"WORD", "PIPE", "CMD", "SCMD", "RDIRS", "RDIR"};

node	*init_node(node *n)
{
	node *new = (node *)malloc(sizeof(node));
	new->type = WORD;
	if (n)
	{
		new->pipe = n->pipe;
		new->level = n->level + 1;
	}
	else
	{
		new->pipe = 0;
		new->level = 0;
	}
	new->left = NULL;
	new->right = NULL;
	new->node_str = NULL;
	return (new);
}

void	make_tree(char *str, node *n)
{
	int	idx;

	idx = -1;
	n->node_str = str;
	while (str[++idx])
	{
		if (case_pipe(str, n, idx))
			return ;
		if (case_cmd(str, n, idx))
			return ;
		if (case_rdir(str, n, idx))
			return ;
	}
	if (n->type == WORD)
	{
		n->type = CMD;
		make_tree(str, n);
	}
}

void	print_tree(node *n)
{
	if (n->left)
		print_tree(n->left);
	if (n->right)
		print_tree(n->right);

	printf("==============\n");
	decode_text(n->node_str);
	printf("%s\n", n->node_str);
	printf("type : %s\n", arr[n->type]); 
	printf("level : %d\n", n->level);
}

// 전위탐색하면서 타입따라서 작동하게?
// RDIR이면 dup하고, SCMD면 빌트인찾거나 exec하고
// 맨밑단은 저거 두개밖에 없으니 저것만 만들면 되나?
// PIPE는 작동을 어케하더라

void	search_tree(t_data *data, node *n)
{
	if (n->left)
		search_tree(data, n->left);
	if (n->right)
		search_tree(data, n->right);
	if (n->type == PIPE)
		;
	else if (n->type == RDIR)
	{
		//printf("::::RDIR::::\n");
		//decode_text(n->node_str);
		//printf("::%s\n", n->node_str);
		set_rdir(n);
	}
	else if (n->type == SCMD)
	{
		// 빌트인인지 아닌지 구분
		// 아니면 명령어 경로 찾아서 exec
		//printf("::::SCMD::::\n");
		set_scmd(data, n);
	}
}

void	make_list(t_list *env, char **envp)
{
	int	idx;

	idx = -1;
	while (envp[++idx])
	{
		env->str = strdup(envp[idx]);
		env->next = malloc(sizeof(t_list));
		env = env->next;
	}
}

void init_tree(char *line, char **envp)
{
	t_data	*data = malloc(sizeof(t_data));
	t_list	*env = malloc(sizeof(t_list));
	make_list(env, envp);

	node *head = init_node(NULL);

	data->env = env;
	data->head = head;

	char *temp;

	temp = set_text(line);
	make_tree(temp, head);
	free(temp);
	
	search_tree(data, head);
}
