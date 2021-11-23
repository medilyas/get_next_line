#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buff;
	char		*p;
	char		src[BUFFER_SIZE + 1];
	int			index;
	int			max;

	if (BUFFER_SIZE <= 0)
		return (0);
	buff = NULL;
	while (1)
	{
		max = read(fd, src, BUFFER_SIZE);
		if (max <= 0)
		{
			if ((!buff || !ft_strcmp(buff, "")) && !temp)
			{
				buff = ft_free(buff);
				return (0);
			}
			else if (buff && !temp)
				return (buff);
			// src[0] = '\0';
		}
		src[max] = '\0';
		if (temp)
		{
			buff = ft_strdup(temp);
			temp = ft_free(temp);
		}
		if (!buff)
			buff = ft_strdup(src);
		else
		{
			p = ft_strjoin(buff, src);
			buff = ft_free(buff);
			buff = p;
			p = NULL;
		}
		if ((index = ft_strchr(buff, 10)) >= 0)
		{

			temp = ft_substr(buff, (index + 1), (ft_strlen(buff) - index - 1));
			p = ft_substr(buff, 0, (index + 1));
			buff = ft_free(buff);
			buff = p;
			break;
		}
		else if (temp)
			temp = ft_free(temp);
	}
	return (buff);
}