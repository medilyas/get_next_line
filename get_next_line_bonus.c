/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:25:55 by mkabissi          #+#    #+#             */
/*   Updated: 2021/11/26 12:26:19 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}

char	*ft_read(char **buff, char **temp, char **src, int fd)
{
	int	max;

	*src = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*src)
		return (0);
	max = read(fd, *src, BUFFER_SIZE);
	if (max <= 0)
	{
		if ((!*buff || !(*buff)[0]) && !*temp)
		{
			*buff = ft_free(*buff);
			*src = ft_free(*src);
			return (0);
		}
		else if (*buff && !*temp)
			*src = ft_free(*src);
	}
	if (*src)
		src[0][max] = '\0';
	if (*temp)
	{
		*buff = ft_strdup(*temp);
		*temp = ft_free(*temp);
	}
	return (*src);
}

char	*ft_complete(char **buff, char **temp, char **src)
{
	char	*p;
	int		index;

	if (!*buff)
		*buff = ft_strdup(*src);
	else
	{
		p = ft_strjoin(*buff, *src);
		*buff = ft_free(*buff);
		*buff = p;
		p = NULL;
	}
	*src = ft_free(*src);
	index = get_nl(*buff);
	if (index >= 0)
	{
		*temp = ft_substr(*buff, (index + 1), (ft_strlen(*buff) - index - 1));
		p = ft_substr(*buff, 0, (index + 1));
		*buff = ft_free(*buff);
		*buff = p;
		return (*buff);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*temp[1024];
	char		*buff;
	char		*p;
	char		*src;

	if ((fd < 0 || fd >= 1024) || BUFFER_SIZE <= 0)
		return (0);
	buff = NULL;
	src = NULL;
	while (1)
	{
		p = ft_read(&buff, &temp[fd], &src, fd);
		if (!p && !buff)
			return (0);
		if (!p && buff)
			return (buff);
		p = NULL;
		p = ft_complete(&buff, &temp[fd], &src);
		if (p)
			break ;
		temp[fd] = ft_free(temp[fd]);
	}
	return (buff);
}
