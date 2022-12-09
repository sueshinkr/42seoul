#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*check_remain(int fd, char *remain);
char	*make_next_line(char *remain);
char	*update_remain(char *remain);

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while(*str++)
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*ret_str;
	char	*ret;

	ret_str = (char *)malloc(ft_strlen(str) * sizeof(char));
	if (!ret_str)
		return (NULL);
	ret = ret_str;
	while (*str)
		*ret_str++ = *str++;
	*ret_str = 0;
	return (ret);
}

char	*ft_strchr(char *str, char ch)
{
	while(*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join_str;
	char	*ret;
	int		join_len;

	join_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join_str = (char *)malloc(join_len * sizeof(char));
	if (!join_str)
		return (NULL);
	ret = join_str;
	while (join_len-- > 0)
	{
		if (*s1)
			*join_str++ = *s1++;
		else
			*join_str++ = *s2++;
	}
	*join_str = 0;
	return (ret);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	while (size-- > 0 && *src)
		*dst++ = *src++;
	*dst = 0;
	return (src_len);
}

char	*check_remain(int fd, char *remain)
{
	char	*buff;
	char	*temp;
	int		read_idx;

	buff = (char *)malloc((BUFFER_SIZE + 1)* sizeof(char));
	while (!remain || !ft_strchr(remain, '\n'))
	{
		read_idx = read(fd, buff, BUFFER_SIZE);
		if (read_idx <= 0)
			break;
		buff[read_idx] = '\0';
		if (!remain)
			remain = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(remain, buff);
			free(remain);
			remain = temp;
		}
	}
	free(buff);
	return (remain);
}

char	*make_next_line(char *remain)
{
	char	*next_line;
	int		len;

	len = 0;
	while (*(remain + len))
	{
		if (*(remain + len++) == '\n')
			break ;
	}
	next_line = (char *)malloc((len + 1)* sizeof(char));
	ft_strlcpy(next_line, remain, len);
	return (next_line);
}

char	*update_remain(char *remain)
{
	char	*fix_remain;
	char	*temp;
	size_t	len;

	fix_remain = ft_strchr(remain, '\n');
	if (!fix_remain)
	{
		free(remain);
		return (NULL);
	}
	len = ft_strlen(fix_remain);
	if (len == 1)
	{
		free(remain);
		return (NULL);
	}
	temp = (char *)malloc(len * sizeof(char));
	ft_strlcpy(temp, fix_remain + 1, len);
	free(remain);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char *remain;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remain = check_remain(fd, remain);
	if (!remain)
		return (NULL);
	next_line = make_next_line(remain);
	remain = update_remain(remain);
	return (next_line);
}