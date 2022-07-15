#include "push_swap.h"

void	sort_select_atob(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	if (count > 0)
		sort_recur_atob_top(a, b, comm, count);
	else
		sort_recur_atob_bottom(a, b, comm, -count);
}

void	sort_select_btoa(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	if (count > 0)
		sort_recur_btoa_top(a, b, comm, count);
	else
		sort_recur_btoa_bottom(a, b, comm, -count);
}

void	sort_recur_atob_top(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	ra;
	int	pb;

	ra = 0;
	pb = 0;
	//ft_printf("atob top count : %d\n", count);
	if (count <= 1 || check_arr(a, count))
		return;
	else if (count == 2)
		sort_two(a, comm);
	else if (count == 3)
		sort_three(a, comm);
	else if (count == 4)
		sort_four(a, b, comm);
/*
	else if (count == 5)
		sort_five(a, b, comm);
*/
	else
	{
		if (check_arr(a, count))
			return ;
		pivot = find_pivot_top(a, count);
		while (count-- > 0)
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
		//node_print(a);
		//node_print(b);
		sort_select_atob(a, b, comm, -ra);
		sort_select_btoa(a, b, comm, pb);
	}
}

void	sort_recur_atob_bottom(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	ra;
	int	pb;

	ra = 0;
	pb = 0;
	//ft_printf("atob bottom count : %d\n", count);
	if (count <= 1)
		return;
	else if (count == 2)
	{
		func_rra(a, comm);
		func_rra(a, comm);
		sort_two(a, comm);
		//node_print(a);
		//node_print(b);
	}
	else if (count == 3)
	{
		func_rra(a, comm);
		func_rra(a, comm);
		func_rra(a, comm);
		sort_three(a, comm);
		//node_print(a);
		//node_print(b);
	}
	else
	{
		//if (check_arr(a, count))
		//	return ;
		pivot = find_pivot_bottom(a, count);
		while (count-- > 0)
		{
			func_rra(a, comm);
			if (a->head->next->num > pivot)
				ra++;
			else
			{
				func_pb(b, a, comm);
				pb++;
			}
		}
		//node_print(a);
		//node_print(b);
		sort_select_atob(a, b, comm, ra);
		sort_select_btoa(a, b, comm, pb);
	}
}

void	sort_recur_btoa_top(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	rb;
	int	pa;

	rb = 0;
	pa = 0;
	//ft_printf("btoa top count : %d\n", count);
	if (count == 1)
		func_pa(a, b, comm);
	else if (count == 2)
	{
		if (b->head->next->num < b->head->next->next->num)
			func_sb(b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
	}
	else if (count == 3)
		sort_three_reverse(a, b, comm);
	else if (count == 4)
		sort_four_reverse(a, b, comm);
	else
	{
		pivot = find_pivot_top(b, count);
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
		sort_select_atob(a, b, comm, pa);
		sort_select_btoa(a, b, comm, -rb);
	}
}

void	sort_recur_btoa_bottom(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	rb;
	int	pa;

	rb = 0;
	pa = 0;
	//ft_printf("btoa bottom count : %d\n", count);
	if (count == 1)
	{
		func_rrb(b, comm);
		func_pa(a, b, comm);
	}
	else
	{
		pivot = find_pivot_bottom(b, count);
		while (count-- > 0)
		{
			func_rrb(b, comm);
			if (b->head->next->num <= pivot)
				rb++;
			else
			{
				func_pa(a, b, comm);
				pa++;
			}
		}
		//node_print(a);
		//node_print(b);
		sort_select_atob(a, b, comm, pa);
		sort_select_btoa(a, b, comm, rb);
	}
}





























void	sort_recur_atob_first(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	ra;
	int	pb;

	ra = 0;
	pb = 0;
	//ft_printf("atob count : %d\n", count);
	if (count <= 1 || check_arr(a, count))
		return;
	else if (count == 2)
		sort_two(a, comm);
	else if (count == 3)
		sort_three_only(a, comm);
	else if (count == 4)
		sort_four(a, b, comm);
	else
	{
		if (check_arr(a, count))
			return ;
		pivot = find_pivot_top(a, count);
		while (count-- > 0)
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
		//node_print(a);
		//node_print(b);
		sort_recur_atob_second(a, b, comm, ra);
		sort_recur_btoa_last(a, b, comm, pb);
	}
}

void	sort_recur_atob_second(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	ra;
	int	pb;

	ra = 0;
	pb = 0;
	//ft_printf("atob count : %d\n", count);
	if (count <= 1 || check_arr(a, count))
		return;
	else if (count == 2)
		sort_two(a, comm);
	else if (count == 3)
		sort_three_only(a, comm);
	else if (count == 4)
		sort_four(a, b, comm);
	else
	{
		if (check_arr(a, count))
			return ;
		pivot = find_pivot_top(a, count);
		while (count-- > 0)
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
		//node_print(a);
		//node_print(b);
		sort_recur_atob_second(a, b, comm, ra);
		sort_select_btoa(a, b, comm, pb);
	}
}

void	sort_recur_btoa_last(t_list *a, t_list *b, t_cmlist *comm, int count)
{
	int	pivot;
	int	rb;
	int	pa;

	rb = 0;
	pa = 0;
	//ft_printf("btoa count : %d\n", count);
	if (count == 1)
		func_pa(a, b, comm);
	else if (count == 2)
	{
		if (b->head->next->num < b->head->next->next->num)
			func_sb(b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
	}
	else if (count == 3)
	{
		sort_three_reverse_only(b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
		func_pa(a, b, comm);
	}
	else
	{
		pivot = find_pivot_top(b, count);
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
		//node_print(a);
		//node_print(b);
		sort_select_atob(a, b, comm, pa);
		sort_recur_btoa_last(a, b, comm, rb);
	}
}
