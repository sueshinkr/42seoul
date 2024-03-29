/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:54:49 by sueshin           #+#    #+#             */
/*   Updated: 2023/02/19 17:45:30 by taehyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	*ft_memset(void *ptr, int value, size_t size)
{
	void	*result;

	result = ptr;
	while (size-- > 0)
		*(unsigned char *)ptr++ = value;
	return (result);
}

int	makecolor(int *color)
{
	int	c;

	c = 0;
	c += (color[0] & 0xff) << 16;
	c += (color[1] & 0xff) << 8;
	c += (color[2] & 0xff);
	return (c);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (s1[idx] != '\0' && s2[idx] != '\0' && idx < n)
	{
		if (s1[idx] != s2[idx])
		{
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		}
		idx++;
	}
	if (idx == n)
		return (0);
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
