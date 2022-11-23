/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:33:34 by sueshin           #+#    #+#             */
/*   Updated: 2022/07/19 00:50:15 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flag
{
	int		minus;
	int		zero;
	int		sharp;
	int		space;
	int		plus;
	size_t	pcs;
	size_t	width;
}	t_flag;

int		ft_printf(const char *str, ...);
void	select_flag(const char **str, va_list *ap, int *count);
void	select_format(const char **str, va_list *ap, int *count, t_flag flag);

char	*ft_substr(char *str, unsigned int start, size_t len);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t size);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int value, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *str, int c);
char	*check_specialzero(char *buf, t_flag flag);
void	buf_print(char *buf, int *count);
char	*ft_itoa(int n, int *minus);
char	*ft_uitoa(unsigned int n);
char	*numtohex(unsigned long long num, int idx, int bigorsmall);
void	reset_flag(t_flag *flag);

void	print_char(va_list *ap, int *count, t_flag flag);
char	*print_str(va_list *ap, char *buf, t_flag flag);
char	*print_pointer(va_list *ap, char *buf, t_flag flag);

char	*print_decimal(va_list *ap, char *buf, t_flag flag);
char	*print_integer(va_list *ap, char *buf, t_flag flag);
char	*print_unsigned_decimal(va_list *ap, char *buf, t_flag flag);
char	*number_case_minus(t_flag flag, char *buf, int minus);
char	*number_case_zero(t_flag flag, char *buf, int minus);
char	*number_case_onlywidth(t_flag flag, char *buf, int minus);
char	*number_case_nowidth(t_flag flag, char *buf, int minus);

char	*print_hex_small(va_list *ap, char *buf, t_flag flag);
char	*print_hex_big(va_list *ap, char *buf, t_flag flag);
char	*print_percent(char *buf, t_flag flag);
char	*hex_case_minus(t_flag flag, char *buf, int bigorsmall);
char	*hex_case_zero(t_flag flag, char *buf, int bigorsmall);
char	*hex_case_onlywidth(t_flag flag, char *buf, int bigorsmall);
char	*hex_case_nowidth(t_flag flag, char *buf, int bigorsmall);

#endif
