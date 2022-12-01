#include "minishell.h"

char	*str_cut_front(char *str, int idx)
{
	char	*tmp;

	while (*str == ' ')
	{
		str++;
		idx--;
	}
	tmp = malloc((idx + 1) * sizeof(char));
	ft_strlcpy(tmp, str, idx);
	tmp[idx] = '\0';
	return (tmp);
}

char	*str_cut_back(char *str, int idx)
{
	char	*tmp;
	int		len;

	while (*(str + idx + 1) == ' ')
		idx++;
	len = ft_strlen(str);
	while (*(str + len - 1) == ' ')
		len--;
	tmp = malloc((len - idx) * sizeof(char));
	ft_strlcpy(tmp, str + idx + 1, len - idx);
	return (tmp);
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

char	*ft_strjoin_nofree(char *str1, char *str2)
{
	char	*joinstr;
	size_t	joinstr_len;
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	idx2 = 0;
	joinstr_len = ft_strlen(str1) + ft_strlen(str2) + 1;
	joinstr = (char *)malloc(joinstr_len * sizeof(char));
	if (!joinstr)
		return (NULL);
	while (*(str1 + idx1))
	{
		*(joinstr + idx1) = *(str1 + idx1);
		idx1++;
	}
	while (*(str2 + idx2))
	{
		*(joinstr + idx1 + idx2) = *(str2 + idx2);
		idx2++;
	}
	*(joinstr + idx1 + idx2) = 0;
	return (joinstr);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*str1_unchar;
	unsigned char	*str2_unchar;

	str1_unchar = (unsigned char *)str1;
	str2_unchar = (unsigned char *)str2;
	while (*str1_unchar || *str2_unchar)
	{
		if (*str1_unchar != *str2_unchar)
			return (*str1_unchar - *str2_unchar);
		str1_unchar++;
		str2_unchar++;
	}
	return (0);
}
