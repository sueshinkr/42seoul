#include <string.h>
#include <stdlib.h>
#include <printf.h>
#include <unistd.h>
#include <fcntl.h>

enum TYPE {WORD, PIPE, CMD, SCMD, RDIRS, RDIR};

char *arr[] = {"WORD", "PIPE", "CMD", "SCMD", "RDIRS", "RDIR"};

typedef struct Node
{
	enum TYPE type;
	struct Node *left;
	struct Node *right;
	char *node_str;

	int level;
} node;

char*	str_cut_front(char *str, int idx)
{
	char *tmp;

	tmp = malloc((idx + 1) * sizeof(char));
	strlcpy(tmp, str, idx);
	tmp[idx] = '\0';
	return tmp;
}

char*	str_cut_back(char *str, int idx)
{
	char *tmp;
	int	len = strlen(str);

	tmp = malloc((len - idx) * sizeof(char));
	strlcpy(tmp, str + idx + 1, len - idx);
	return tmp;
}

void make_tree(char *str, node *n)
{
	int idx = -1;
	int check = 0;

	n->node_str = str;
	if (n->type == SCMD)
		return ;

	while(str[++idx])
	{
		if (str[idx] == '|')
		{
			n->type = PIPE;
			n->left = malloc(sizeof(node));
			n->left->type = CMD;
			n->left->level = n->level + 1;
			make_tree(str_cut_front(str, idx), n->left);

			n->right = malloc(sizeof(node));
			n->right->level = n->level + 1;
			make_tree(str_cut_back(str, idx), n->right);

			return ;
		}

		if (n->type == CMD && strchr("<>", str[idx]))
		{
			while (str[++idx])
			{
				if (check == 0 && !strchr("<> ", str[idx]))
					check = 1;
				else if (check == 1 && strchr("<>", str[idx]))
					check = 0;
				else if (check == 1 && !strchr("<> ", str[idx]))
				{
					n->left = malloc(sizeof(node));
					n->left->type = RDIR;
					n->left->level = n->level + 1;
					make_tree(str_cut_front(str, idx), n->left);

					n->right = malloc(sizeof(node));
					n->right->type = CMD;
					n->right->level = n->level + 1;
					make_tree(str_cut_back(str, idx - 1), n->right);

					return ;
				}
			}
		}

		if (n->type == CMD && !strchr("<> ", str[idx]))
		{
			while (str[++idx])
			{
				if (strchr("<>", str[idx]))
				{
					n->left = malloc(sizeof(node));
					n->left->type = RDIR;
					n->left->level = n->level + 1;
					make_tree(str_cut_back(str, idx - 1), n->left);

					n->right = malloc(sizeof(node));
					n->right->type = SCMD;
					n->right->level = n->level + 1;
					make_tree(str_cut_front(str, idx), n->right);

					return ;
				}
			}

			n->right = malloc(sizeof(node));
			n->right->type = SCMD;
			n->right->level = n->level + 1;
			make_tree(str, n->right);

			return ;
		}

		if (n->type == RDIR && strchr("<>", str[idx]))
		{
			while(str[++idx])
			{
				if (strchr("<>", str[idx]) && str[idx] != str[idx - 1])
				{
					n->type = RDIRS;

					n->left = malloc(sizeof(node));
					n->left->type = RDIR;
					n->left->level = n->level + 1;
					make_tree(str_cut_front(str, idx), n->left);

					n->right = malloc(sizeof(node));
					n->right->type = RDIR;
					n->right->level = n->level + 1;
					make_tree(str_cut_back(str, idx - 1), n->right);

					return ;
				}
			}

			return ;
		}
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
		printf("::%s\n", n->node_str);
		set_RDIR(n);
	}
	else if (n->type == SCMD)
		;
	
}

void init_tree(char *line)
{
	node *head = malloc(sizeof(node));
	head->level = 0;

	make_tree(line, head);
	//search_tree(head);

	print_tree(head);
}

/*
// 따옴표 벗겨내는 작업 필요
char* set_text(char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
	{
		if (str[idx])
	}
}
*/