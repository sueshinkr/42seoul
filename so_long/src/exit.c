#include "so_long.h"

void	exit_game_with_map(int flag, t_data *data)
{
	if (flag == 0)
		printf("Empty input map : Error\n");
	else if (flag == 1)
		printf("Wrong character input : Error\n");
	else if (flag == 2)
		printf("Wrong wall : Error\n");
	else if (flag == 3)
		printf("Not rectangular map : Error\n");
	else if (flag == 4)
		printf("Nonvalidated character : Error\n");
	else if (flag == 5)
		printf("Exit Game...\n");
	else if (flag == 6)
		printf("Game Clear!\n");
	else if (flag == 7)
		printf("Don't touch the cow!\n");
	exit(0);
}

int	exit_game_with_red()
{
	printf("Exit Game...\n");
	exit(0);
} 

int	cal_count(int n)
{
	int				count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long long	nb;

	nb = n;
	count = cal_count(nb);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		*str = '0';
	*(str + count) = 0;
	while (nb > 0)
	{
		*(str + --count) = nb % 10 | '0';
		nb /= 10;
	}
	return (str);
}