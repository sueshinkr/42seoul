/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:33:34 by sueshin           #+#    #+#             */
/*   Updated: 2022/05/13 13:20:46 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
//# include "libft.h"

int		ft_printf(const char *str, ...);
void	select_flag(char **str, va_list *ap, int *count);
void	select_format(char **str, va_list *ap, int *count, int *flag);
void	print_char(va_list *ap, int *count, int *flag);
void	print_str(va_list *ap, int *count, int *flag);
void	print_pointer(va_list *ap, int *count, int *flag);
void	addresstohex(unsigned long long num, int *count);
void	print_decimal(va_list *ap, int *count, int *flag);
void	print_integer(va_list *ap, int *count, int *flag);
void	print_unsigned_decimal(va_list *ap, int *count, int *flag);
int		cal_count(long long n);
char	*ft_uitoa(unsigned int n);
void	print_hex_small(va_list *ap, int *count, int *flag);
void	print_hex_big(va_list *ap, int *count, int *flag);
int		cal_count_16(unsigned int n);
char	*numtohex(unsigned int num, int bigorsmall);
void	print_percent(va_list *ap, int *count, int *flag);

#endif
