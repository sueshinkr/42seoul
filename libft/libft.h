#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *ptr, size_t size);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t size);
size_t	ft_strlcpy(char *restrict dest, char *restrict src, size_t size);
size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	*ft_memchr(const void *str, int value, size_t size);
int		ft_memcmp(const void *dst, const void *src, size_t size);
char	*ft_strnstr(const char *desert, const char *needle, size_t size);

#endif
