#include "minishell.h"

char *arr[] = {"WORD", "PIPE", "CMD", "SCMD", "RDIRS", "RDIR"};

void	make_tree(char *str, node *n)
{
	int idx = -1;
	int check = 0;

	printf("::: str : %s\n", str);
	if(!str)
	{
		printf("null\n");
		return ;
	}
	n->node_str = str;

	while(str[++idx])
	{
		if (case_pipe(str, n, idx))
			return ;
		if (case_cmd(str, n, idx))
			return ;
		if (case_rdir(str, n, idx))
			return ;
	}
	n->type = CMD;
	make_tree(str, n);
}

// <a < b cat >c | echo "abc"
// ls -a -l >> a < b > c | grep "" | cat << x > y

void	print_tree(node *n)
{
	if (n->left)
		print_tree(n->left);
	if (n->right)
		print_tree(n->right);

	printf("==============\n");
	printf("%s\n", n->node_str);
	printf("type : %s\n", arr[n->type]);
	printf("level : %d\n", n->level);
}

// 전위탐색하면서 타입따라서 작동하게?
// RDIR이면 dup하고, SCMD면 빌트인찾거나 exec하고
// 맨밑단은 저거 두개밖에 없으니 저것만 만들면 되나?
// PIPE는 작동을 어케하더라

void set_RDIR(node *n)
{
	char	*rdir;
	char	*file;
	int		fd;
	int		idx = -1;
	// < 분리

	while (strchr("<>", n->node_str[++idx]))
		;
	rdir = str_cut_front(n->node_str, idx + 1);
	while (n->node_str[idx] == ' ')
		idx++;
	file = str_cut_back(n->node_str, idx - 1);


	printf("rdir:%s, file :%s!\n", rdir, file);
/*
	if (strcmp(rdir, "<"))
	{
		if (access(file, F_OK) == -1)
			; // 에러
		fd = open(file, O_RDONLY);
		if (fd < 0)
			; // 에러
		if (dup2(fd, 0) == -1)
			; // 에러
	}
	else if (strcmp(rdir, "<<"))
	{
		;
	}
	else if (strcmp(rdir, ">"))
	{
		//fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd < 0)
			; // 에러
		if (dup2(fd, 1) == -1)
			; // 에러
	}
	else if (strcmp(rdir, ">>"))
	{
		if (access(file, F_OK) == -1)
			; //fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
		else
			; //fd = open(file, O_RDWR | O_APPEND, 0644);
		if (fd < 0)
			; // 에러
		if (dup2(fd, 1) == -1)
			; // 에러
	}
	*/
}

void	search_tree(node *n)
{
	if (n->left)
		search_tree(n->left);
	if (n->right)
		search_tree(n->right);

	if (n->type == PIPE)
		;
	else if (n->type == RDIR)
	{
		decode_text(n->node_str);
		printf("::%s\n", n->node_str);
		set_RDIR(n);
	}
	else if (n->type == SCMD)
	{
		printf("SCMD::::\n");
		printf("str::%s\n", n->node_str);
		decode_text(n->node_str);
		printf("::%s\n", n->node_str);
	}
	
}

void init_tree(char *line)
{
	node *head = malloc(sizeof(node));
	head->level = 0;

	char *temp;

	temp = set_text(line);
	decode_text(temp);
	printf("... %s\n", temp);

	make_tree(temp, head);
	printf("after make\n");
	print_tree(head);
	printf("after print\n");
	search_tree(head);

	//
}
