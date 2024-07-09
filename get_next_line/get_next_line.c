#include <unistd.h>
#include <stdlib.h>

int 	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*new_line;

	len = ft_strlen(s);
	new_line = malloc(len + 1);
	ft_strcpy(new_line, s);
	return (new_line);
}

char	*ft_strchr(const char *src, char c)
{
	char *s;

	s = (char *)src;
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(res + len1, s2);
	free(s1);
	return (res);
}

#define BUFFER_SIZE 42

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char 		*line;
	char 		*new_line;
	size_t		byte_read;
	int 	to_copy;

	line = ft_strdup(buffer);
	while (!(new_line = ft_strchr(line, '\n')) && (byte_read = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[byte_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	if (new_line != NULL)
	{
		to_copy = new_line - line + 1;
		ft_strcpy(buffer, new_line + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		buffer[0] = '\0';
	}
	line[to_copy] = '\0';
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s" , get_next_line(fd));
	printf("%s" , get_next_line(fd));
	printf("%s" , get_next_line(fd));
	printf("%s" , get_next_line(fd));
}