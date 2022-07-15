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
	sort_three(a, comm);
	if (b->head->next->num > b->tail->next->num)
		func_sb(b, comm);
	func_pa(a, b, comm);
	func_pa(a, b, comm);
	func_ra(a, comm);
}

void	sort_recur_atob(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	ra;
	int	pb;
	int	idx;

	ra = 0;
	pb = 0;
	//ft_printf("atob count : %d\n", count);
	if (count <= 1 || check_arr(a, count))
		return;
	else if (count == 2)
		sort_two(a, comm);
	else if (count == 3)
		sort_three(a, comm);
	else if (count == 5)
		sort_five(a, b, comm);
	else
	{
		if (check_arr(a, count))
			return ;
		pivot = find_pivot(a, count);
		idx = find_maxidx(a, pivot, count);
		//ft_printf("atob pivot : %d, idx : %d\n", pivot, idx);
		while (idx-- > 0)
		{
			if (a->head->next->num > pivot)
			{
				func_ra(a, comm);
				ra++;
			}
			else
			{
				func_pb(b, a, comm);
				pb++;
			}
		}
		while (idx++ < ra - 1)
			func_rra(a, comm);
		//node_print(a);
		//node_print(b);
		sort_recur_atob(a, b, comm, count - pb);
		sort_recur_btoa(a, b, comm, pb);
	}
}

void	sort_recur_btoa(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	rb;
	int	pa;

	rb = 0;
	pa = 0;
	//ft_printf("btoa count : %d\n", count);
	if (count == 1)
		func_pa(a, b, comm);
	else
	{
		pivot = find_pivot(b, count);
		while (count-- > 0)
		{

			if (b->head->next->num <= pivot)
			{
				func_rb(b, comm);
				rb++;
			}
			else
			{
				func_pa(a, b, comm);
				pa++;
			}
		}
		while (count++ < rb - 1)
			func_rrb(b, comm);
		//node_print(a);
		//node_print(b);
		sort_recur_atob(a, b, comm, pa);
		sort_recur_btoa(a, b, comm, rb);
	}
}