#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buff;
	char		src[BUFFER_SIZE + 1];
	int			index;
	int			max;
	int			n;

	n = 0;
	if (BUFFER_SIZE <= 0)
		return (0);
	buff = NULL;
	while (1)
	{
		max = read(fd, src, BUFFER_SIZE);
		if (max <= 0)
		{
			if ((!buff || !ft_strcmp(buff, "")) && !temp)
				return (0);
			else if (buff && !temp)
				return (buff);
			src[0] = '\0';
		}
		src[max] = '\0';
		if (temp)
			buff = ft_strdup(temp);
		if (!buff)
			buff = ft_strdup(src);
		else
		{
			buff = ft_strjoin(buff, src);
			n += BUFFER_SIZE;
		}
		if ((index = ft_strchr(buff, 10)) >= 0)
		{
			temp = ft_substr(buff, (index + 1), (ft_strlen(buff) - index - 1));
			buff = ft_substr(buff, 0, (index + 1));
			break;
		}
		else if (temp)
			temp = ft_free(temp);
	}
	return (buff);
}

int main()
{
	int fd = open("myfile.txt", O_RDWR);
	char *buff;
	int i = 0;

	while (++i <= 3) {
		buff = get_next_line(fd);
		printf("/~~~~~ line_%d ~~~~~/\n>%s\n\n", i, buff);
	}

	
	return (0);
}
