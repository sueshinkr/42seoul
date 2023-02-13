#include "cub3d.h"

void	exit_game_with_map(int flag)
{
	if (flag == 0)
		printf("Empty input map : Error\n");
	else if (flag == 1)
		printf("Wrong wall : Error\n");
	else if (flag == 2)
		printf("Wrong character input : Error\n");
	else if (flag == 3)
		printf("More than one player : Error\n");
	else if (flag == 4)
		printf("Wrong color range : Error\n");
	else if (flag == 5)
		printf("Exit Game...\n");
	else if (flag == 6)
		printf("Game Clear!\n");
	else if (flag == 7)
		printf("Don't touch the cow!\n");
	exit(0);
}

char	*ft_strjoin_len(char *str1, char *str2, int len)
{
	char	*joinstr;
	size_t	joinstr_len;
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	idx2 = 0;
	joinstr_len = ft_strlen(str1) + len + 1;
	joinstr = (char *)malloc(joinstr_len * sizeof(char));
	if (!joinstr)
		return (NULL);
	while (*(str1 + idx1))
	{
		*(joinstr + idx1) = *(str1 + idx1);
		idx1++;
	}
	while (*(str2 + idx2) && len-- > 0)
	{
		*(joinstr + idx1 + idx2) = *(str2 + idx2);
		idx2++;
	}
	*(joinstr + idx1 + idx2) = 0;
	free(str1);
	return (joinstr);
}