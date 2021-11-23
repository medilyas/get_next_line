#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1lenght;
	size_t	s2lenght;
	char	*p;

	if (!s1 || !s2)
		return (0);
	s1lenght = ft_strlen(s1);
	s2lenght = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (s1lenght + s2lenght + 1));
	if (!p)
		return (0);
	ft_memcpy(p, s1, s1lenght);
	p[s1lenght] = '\0';
	ft_strlcat(p, s2, s1lenght, s2lenght);
	return (p);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!d && !s)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

void	ft_strlcat(char *dst, const char *src, size_t dstlen, size_t srclen)
{
	size_t	i;

	i = 0;
	while (i < srclen)
	{
		dst[dstlen + i] = src [i];
		i++;
	}
	dst[dstlen + i] = '\0';
}

int		ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
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
	i = 0;
	while (i < len && s[i])
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strcmp(char	*s1, char	*s2)
{
	int				i;
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = 0;
	while (a1[i] == a2[i] && a1[i] && a2[i])
	{
		i++;
	}
	if (a1[i] == a2[i])
		return (0);
	return (1);
}

char	*ft_free(char *s)
{
	free(s);
	return (NULL);
}