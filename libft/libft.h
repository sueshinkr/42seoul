#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t size);
size_t	ft_strlcpy(char *restrict dest, char *restrict src, size_t size);

#endif
