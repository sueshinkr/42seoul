#include "push_swap.h"

void	sort_two(t_list *list, t_cmlist *comm)
{
	if (list->head->next->num > list->head->next->next->num)
		func_sa(list, comm);
}

void	sort_three_only(t_list *a, t_cmlist *comm)
{
	t_node	*top;

	top = a->head->next;
	if (top->num > top->next->num && top->num > top->next->next->num)
	{
		func_ra(a, comm);
		if (top->next->num > top->next->next->num)
			func_sa(a, comm);
	}
	else if (top->num < top->next->num && top->num < top->next->next->num)
	{
		if (top->next->num > top->next->next->num)
		{
			func_sa(a, comm);
			func_ra(a, comm);
		}
	}
	else if (top->num > top->next->num)
		func_sa(a, comm);
	else
		func_rra(a, comm);
}

void	sort_five_only(t_list *a, t_list *b, t_cmlist *comm)
{
	int		idx;
	int		max;
	int		min;
	
	idx = 5;
	check_minmax(a, &max, &min);
	while (idx-- > 0)
	{
		if (a->head->next->num == max || a->head->next->num == min)
			func_pb(b, a, comm);
		else
			func_ra(a, comm);
	}
	sort_three_only(a, comm);
	if (b->head->next->num > b->tail->next->num)
		func_sb(b, comm);
	func_pa(a, b, comm);
	func_pa(a, b, comm);
	func_ra(a, comm);
}

void	sort_three(t_list *a, t_cmlist *comm)
{
	t_node	*top;

	top = a->head->next;
	if (top->num > top->next->num && top->num > top->next->next->num)
	{
		func_sa(a, comm);
		func_ra(a, comm);
		func_sa(a, comm);
		func_rra(a, comm);
		if (a->head->next->num > a->head->next->next->num)
			func_sa(a, comm);
	}
	else if (top->num < top->next->num && top->num < top->next->next->num)
	{
		if (top->next->num > top->next->next->num)
		{
			func_ra(a, comm);
			func_sa(a, comm);
			func_rra(a, comm);
		}
	}
	else if (top->num > top->next->num)
		func_sa(a, comm);
	else
	{
		func_ra(a, comm);
		func_sa(a, comm);
		func_rra(a, comm);
		func_sa(a, comm);
	}
}

void	sort_three_reverse_only(t_list *b, t_cmlist *comm)
{
	t_node	*top;

	top = b->head->next;
	if (top->num < top->next->num && top->num < top->next->next->num)
	{
		func_rb(b, comm);
		if (top->next->num < top->next->next->num)
			func_sb(b, comm);
	}
	else if (top->num < top->next->num && top->num > top->next->next->num)
	{
		if (top->next->num < top->next->next->num)
		{
			func_sb(b, comm);
			func_rb(b, comm);
		}
	}
	else if (top->num < top->next->num)
		func_sb(b, comm);
	else
		func_rrb(b, comm);
}

void	sort_three_reverse(t_list *a, t_list *b, t_cmlist *comm)
{
	t_node	*top;

	top = b->head->next;
	if (top->num < top->next->num && top->num < top->next->next->num)
	{
		func_pa(a, b, comm);
		if (b->head->next->num < b->head->next->next->num)
			func_sb(b, comm);
		func_pa(a, b, comm);
		func_sa(a, comm);
		func_pa(a, b, comm);
		func_sa(a, comm);		
	}
	else if (top->num > top->next->num && top->num > top->next->next->num)
	{
		func_pa(a, b, comm);
		if (b->head->next->num < b->head->next->next->num)
			func_sb(b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
	}
	else if (top->num < top->next->num)
	{
		func_sb(b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
	}
	else
	{
		func_pa(a, b, comm);
		func_sb(b, comm);
		func_pa(a, b, comm);
		func_sa(a, comm);
		func_pa(a, b, comm);
	}
}

void	sort_four(t_list *a, t_list *b, t_cmlist *comm)
{
	int		idx;
	int		min1;
	int		min2;
	int		flag;
	
	idx = 4;
	flag = 0;
	check_min(a, &min1, &min2);
	while (idx-- > 0)
	{
		if (flag == 2)
			break;
		if (a->head->next->num == min1 || a->head->next->num == min2)
		{
			func_pb(b, a, comm);
			flag++;
		}
		else
			func_ra(a, comm);
	}
	while (idx++ < 1)
		func_rra(a, comm);
	if (a->head->next->num > a->head->next->next->num)
		func_sa(a, comm);
	if (b->head->next->num < b->head->next->next->num)
		func_sb(b, comm);
	func_pa(a, b, comm);
	func_pa(a, b, comm);
}

void	sort_four_reverse(t_list *a, t_list *b, t_cmlist *comm)
{
	int		idx;
	int		max1;
	int		max2;
	int		flag;
	
	idx = 4;
	flag = 0;
	check_max(b, &max1, &max2);
	while (idx-- > 0)
	{
		if (flag == 2)
			break;
		if (b->head->next->num == max1 || b->head->next->num == max2)
		{
			func_pa(a, b, comm);
			flag++;
		}
		else
			func_rb(b, comm);
	}
	while (idx++ < 1)
		func_rrb(b, comm);
	if (b->head->next->num < b->head->next->next->num)
		func_sb(b, comm);
	if (a->head->next->num > a->head->next->next->num)
		func_sa(a, comm);
	func_pa(a, b, comm);
	func_pa(a, b, comm);
}

/*
void	sort_five(t_list *a, t_list *b, t_cmlist *comm)
{
	int		idx;
	int		max;
	int		min;
	
	idx = 5;
	check_minmax(a, &max, &min);
	while (idx-- > 0)
	{
		if (a->head->next->num == max || a->head->next->num == min)
			func_pb(b, a, comm);
		else
			func_ra(a, comm);
	}
	func_rra(a, comm);
	func_rra(a, comm);	
	func_rra(a, comm);
	sort_three(a, comm);
	if (b->head->next->num > b->tail->next->num)
		func_sb(b, comm);
	func_pa(a, b, comm);
	func_pa(a, b, comm);
	func_ra(a, comm);
}
*/
