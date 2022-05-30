#include "ft_printf_bonus.h"

char	*number_case_minus(size_t *flag, char *buf, int minus)
{
	char	*temp;
	int		len;

	len = ft_strlen(buf);
	if (minus == 1)
		len++;
	temp = (char *)calloc(flag[6] - len + 1, sizeof(char)); 
	ft_memset(temp, ' ', flag[6] - len);
	buf = ft_strjoin(buf, temp);
	if (minus == 1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag[3] == 1) // " "
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag[4] == 1) // "+"
		buf = ft_strjoin(ft_strdup("+"), buf);
	return (buf);
}

char	*number_case_zero(size_t *flag, char *buf, int minus)
{
	char	*temp;
	int		len;

	len = ft_strlen(buf);
	if (minus == 1)
		len++;
	temp = (char *)calloc(flag[6] - len + 1, sizeof(char)); 
	ft_memset(temp, '0', flag[6] - len);
	buf = ft_strjoin(temp, buf);
	if (minus == 1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag[3] == 1) // " "
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag[4] == 1) // "+"
		buf = ft_strjoin(ft_strdup("+"), buf);
	
	return (buf);
}

char	*number_case_onlywidth(size_t *flag, char *buf, int minus)
{
	char	*temp;

	if (minus == 1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag[3] == 1) // " "
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag[4] == 1) // "+"
		buf = ft_strjoin(ft_strdup("+"), buf);
	temp = (char *)calloc(flag[6] - ft_strlen(buf) + 1, sizeof(char)); 
	ft_memset(temp, " ", flag[6] - ft_strlen(buf));
	buf = ft_strjoin(temp, buf);
	return (buf);
}

char	*number_case_nowidth(size_t *flag, char *buf, int minus)
{
	if (minus == 1)
		buf = ft_strjoin(ft_strdup("-"), buf);
	else if (flag[3] == 1) // " "
		buf = ft_strjoin(ft_strdup(" "), buf);
	else if (flag[4] == 1) // "+"
		buf = ft_strjoin(ft_strdup("+"), buf);
	return(buf);
}
