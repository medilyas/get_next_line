#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buff;
	char		*src;
	int			index;
	int			max;
	int			len;

	len = 0;
	if (BUFFER_SIZE <= 0)
		return (0);
	src = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!src)
		return (0);
	buff = NULL;
	while (1)
	{
		max = read(fd, src, BUFFER_SIZE);
		if (max <= 0)
		{
			if (!buff && !temp)
				return (0);
			else if (buff && !temp)
				return (buff);
		}
		len += BUFFER_SIZE;
		//printf("~~(len == %d)~~\n", len);
		src[max] = '\0';
		if (temp)
			buff = ft_strdup(temp/*, BUFFER_SIZE*/);
		if (!buff)
			buff = ft_strdup(src/*, BUFFER_SIZE*/);
		else
			buff = ft_strjoin(buff, src);
		if ((index = ft_strchr(buff, 10)))
		{
			//printf("T~~~~founded~~(%d)~~(max == %d)~~~T\n", index, max);
			temp = ft_substr(buff, (index + 1), (len - index - 1));
			buff = ft_substr(buff, 0, (index + 1));
			//printf("temp == %s\n\n", temp);
			break;
		}
		else
			{
				free(temp);
				temp = NULL;
			}
	}
	free(src);
	src = NULL;

	return (buff);
}

int main()
{
	int fd = open("myfile.txt", O_RDONLY);
	char *buff;
	int i = 0;

	while (++i <= 7) {
		buff = get_next_line(fd);
		printf("/////_Result_%d_/////\n%s\n\n", i, buff);
	}
	
	return (0);
}
