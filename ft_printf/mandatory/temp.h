#ifndef TEMP_H
# define TEMP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	select_format(const char *str, va_list *ap, int *count);
void 	print_char(va_list *ap, int *count);
void	print_str(va_list *ap, int *count);
void	print_ptr(va_list *ap, int *count);

void	print_dec(va_list *ap, int *count);
void	print_int(va_list *ap, int *count);
void	print_udec(va_list *ap, int *count);

void	print_hex(va_list *ap, int *count);
void	print_HEX(va_list *ap, int *count);


#endif