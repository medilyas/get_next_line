/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:26:56 by mkabissi          #+#    #+#             */
/*   Updated: 2021/11/26 12:27:04 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght])
		++lenght;
	return (lenght);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		len;
	size_t	i;

	i = -1;
	len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0)
		return (0);
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1lenght;
	size_t	s2lenght;
	size_t	i;
	char	*p;

	i = -1;
	if (!s1 || !s2)
		return (0);
	s1lenght = ft_strlen(s1);
	s2lenght = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (s1lenght + s2lenght + 1));
	if (!p)
		return (0);
	while (++i < s1lenght)
		p[i] = s1[i];
	p[s1lenght] = '\0';
	i = -1;
	while (++i < s2lenght)
		p[s1lenght + i] = s2 [i];
	p[s1lenght + i] = '\0';
	return (p);
}

int	get_nl(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (0);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	i = -1;
	while (++i < len && s[i])
		p[i] = s[start + i];
	p[i] = '\0';
	return (p);
}
