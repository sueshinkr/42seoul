/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:33:34 by sueshin           #+#    #+#             */
/*   Updated: 2022/05/25 19:55:01 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_substr(char *str, unsigned int start, size_t len);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t size);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int value, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_itoa(int n);

int		ft_printf(const char *str, ...);
void	select_flag(char **str, va_list *ap, int *count);
void	select_format(char **str, va_list *ap, int *count, size_t *flag);

void	print_char(va_list *ap, int *count, size_t *flag);

void	print_str(va_list *ap, int *count, size_t *flag);
void	print_pointer(va_list *ap, int *count, size_t *flag);
void	addresstohex(unsigned long long num, int *count);
void	print_decimal(va_list *ap, int *count, size_t *flag);
void	print_integer(va_list *ap, int *count, size_t *flag);
void	print_unsigned_decimal(va_list *ap, int *count, size_t *flag);
int		cal_count(long long n);
char	*ft_uitoa(unsigned int n);

int		cal_count_16(unsigned int n);
char	*numtohex(unsigned int num, int bigorsmall);
void	print_hex_small(va_list *ap, int *count, size_t *flag);
void	print_hex_big(va_list *ap, int *count, size_t *flag);
char	*hex_case_minus(size_t *flag, char *buf, int bigorsmall);
char	*hex_case_zero(size_t *flag, char *buf, int bigorsmall);
char	*hex_case_onlywidth(size_t *flag, char *buf, int bigorsmall);
char	*hex_case_nowidth(size_t *flag, char *buf, int bigorsmall);


#endif
