#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_node
{
	int			num;
	struct s_node	*next;
} t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		count;
} t_list;


int	ft_atoi(const char	*str)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + *str - '0';
		else
			break ;
		str++;
	}
	if (result > LONG_MAX)
		return (-1 + (sign < 0));
	return (sign * (int)result);
}

void	push_stack(t_list *list, int n)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->num = n;
	if (!list->head->next)
	{
		list->head->next = new;
		list->tail->next = new;
	}
	else
	{
		list->tail->next->next = new;
		list->tail->next = new;
		new->next = list->head->next;
	}
	list->count++;
}

void	func_sa(t_list *list)
{
	t_node *temp;

	if (list->count < 2)
		return ;
	else if (list->count == 2)
	{
		temp = list->head->next;
		list->head->next = list->tail->next;
		list->head->next->next = temp;
		list->tail->next = temp;
		temp->next = list->head->next;
	}
	else
	{
		temp = list->head->next;
		list->head->next = list->head->next->next;
		temp->next = temp->next->next;
		list->head->next->next = temp;
		list->tail->next->next = list->head->next;
	}
}

void	func_ra(t_list *list)
{
	if (list->count > 1)
	{
		list->tail->next = list->head->next;
		list->head->next = list->head->next->next;
	}
}

void	func_rra(t_list *list)
{
	int	count;
	t_node *temp;

	count = list->count;
	temp = list->head;
	if (count > 1)
	{
		while (count-- > 1)
			temp = temp->next;
		list->head->next = list->tail->next;
		list->tail->next = temp;
	}
}

void	node_print(t_list *list)
{
	int idx = -1;
	t_node	*temp;

	temp = list->head;
	while (++idx < list->count)
	{
		temp = temp->next;
		printf("idx %d : %d\n", idx, temp->num);
	}
}

int	main(int argc, char **argv)
{
	t_list *a;
	int	idx;

	a = malloc(sizeof(t_list));
	a->head = malloc(sizeof(t_node));
	a->tail = malloc(sizeof(t_node));
	a->count = 0;
	idx = 0;
	if (argc < 2)
		return (0);
	while (argv[++idx])
		push_stack(a, ft_atoi(argv[idx]));

	node_print(a);

	printf("::::sa\n");
	func_sa(a);
	node_print(a);
	


	printf(":::::ra\n");
	func_ra(a);
	node_print(a);


	printf(":::::rra\n");
	func_rra(a);
	node_print(a);

}