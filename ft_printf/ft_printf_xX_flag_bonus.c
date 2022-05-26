#include "ft_printf_bonus.h"

char	*hex_case_minus(size_t *flag, char *buf, int bigorsmall)
{
	char	*temp;

	if (flag[2] == 1 && ft_strncmp(buf, "0", sizeof(buf))) // '#'
	{
		if (bigorsmall == 1)
			buf = ft_strjoin(ft_strdup("0X"), buf);
		else
			buf = ft_strjoin(ft_strdup("0x"), buf);
	}
	if (flag[6] > ft_strlen(buf))
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
		ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
		buf = ft_strjoin(buf, temp);
	}
	return (buf);
}

char	*hex_case_onlywidth(size_t *flag, char *buf, int bigorsmall)
{
	char	*temp;

	if (flag[2] == 1) // '#'
	{
		if (bigorsmall == 1)
			buf = ft_strjoin(ft_strdup("0X"), buf);
		else
			buf = ft_strjoin(ft_strdup("0x"), buf);
	}
	temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
	ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
	buf = ft_strjoin(temp, buf);
	return (buf);
}

/*
char	*hex_case_zero1(size_t *flag, char *buf, int bigorsmall)
{
	char	*temp;

	if (flag[5] > 0) // dop
	{
		if (flag[2] == 1) // '#'
		{
			if (bigorsmall == 1)
				buf = ft_strjoin(ft_strdup("0X"), buf);
			else
				buf = ft_strjoin(ft_strdup("0x"), buf);
		}
		temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
		ft_memset(temp, ' ', flag[6] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	else
		buf = hex_case_zero2(flag, buf, bigorsmall);
	return (buf);
}
*/

char	*hex_case_zero(size_t *flag, char *buf, int bigorsmall)
{
	char	*temp;

	if (flag[2] == 1) // #
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) - 1, sizeof(char)); 
		ft_memset(temp, '0', flag[6] - ft_strlen(buf) - 2);
		buf = ft_strjoin(temp, buf);
		if (bigorsmall == 1)
				buf = ft_strjoin(ft_strdup("0X"), buf);
		else
				buf = ft_strjoin(ft_strdup("0x"), buf);
	}
	else
	{
		temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
		ft_memset(temp, '0', flag[6] - ft_strlen(buf));
		buf = ft_strjoin(temp, buf);
	}
	return (buf);
}

char	*hex_case_nowidth(size_t *flag, char *buf, int bigorsmall)
{
	if (flag[2] == 1 && ft_strncmp(buf, "0", sizeof(buf))) // #
	{
		if (bigorsmall == 1)
			buf = ft_strjoin(ft_strdup("0X"), buf);
		else
			buf = ft_strjoin(ft_strdup("0x"), buf);
	}
	return (buf);
}
