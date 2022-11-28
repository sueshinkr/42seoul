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
	strlcpy(tmp, str, idx);
	tmp[idx] = '\0';
	return (tmp);
}

char	*str_cut_back(char *str, int idx)
{
	char	*tmp;
	int		len;

	while (*(str + idx + 1) == ' ')
		idx++;
	len = strlen(str);
	while (*(str + len - 1) == ' ')
		len--;
	tmp = malloc((len - idx) * sizeof(char));
	strlcpy(tmp, str + idx + 1, len - idx);
	return (tmp);
}

char	*ft_strjoin(char *str1, char *str2, int len)
{
	char	*joinstr;
	size_t	joinstr_len;
	size_t	idx1;
	size_t	idx2;

	idx1 = 0;
	idx2 = 0;
	joinstr_len = strlen(str1) + len + 1;
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

char	*ft_strdup(const char *s1)
{
	int		len;
	int		idx;
	char	*dest;

	idx = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (NULL);
	while (idx < len)
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
