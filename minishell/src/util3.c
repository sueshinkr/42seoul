#include "minishell.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(char *key, char *val)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list) * 1);
	if (!lst)
		return (0);
	lst->key = key;
	lst->value = val;
	lst->next = NULL;
	return (lst);
}

int	is_numeric(char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] >= '0' && s[idx] <= '9')
			;
		else
			return (0);
		idx++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	result;

	minus = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += ((*str) - '0') * minus;
		str++;
	}
	return (result);
}

void	free_arr(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}
