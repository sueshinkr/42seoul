/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:33:34 by sueshin           #+#    #+#             */
/*   Updated: 2022/10/26 13:30:49 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	select_format(const char *str, va_list *ap, int *count);
void	print_char(va_list *ap, int *count);
void	print_str(va_list *ap, int *count);
void	print_pointer(va_list *ap, int *count);
void	addresstohex(unsigned long long num, int *count);
void	print_decimal(va_list *ap, int *count);
void	print_integer(va_list *ap, int *count);
void	print_unsigned_decimal(va_list *ap, int *count);
int		cal_count(long long n);
char	*ft_uitoa(unsigned int n);
void	print_hex_small(va_list *ap, int *count);
void	print_hex_big(va_list *ap, int *count);
void	numtohex(long long num, int bigorsmall, int *count);

#endif
