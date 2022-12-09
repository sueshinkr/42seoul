#include <unistd.h>

int ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	
	return (len);
}

char *ft_strdup(char *str)
{
	char *ret;
	int len;
	int i = -1;

	len = ft_strlen(str) + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	while (str[++i])
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}

char get_next_line(int fd)
{
	int r = 0;
	int i = 0;
	char c;
	char buf[100000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return 0;
	
	while ((r = read(fd, &c, 1)) > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break;
	}
	buf[i] = 0;
	if (i == 0 && r <= 0)
		return (0);
	return (ft_strdup(buf));
}