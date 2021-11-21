#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	lenght;

	i = -1;
	lenght = 0;
	while (s[++i])
		++lenght;
	return (lenght);
}

char	*ft_strdup(const char *s1/*, size_t len*/)
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
	ft_strlcat(p, s2, s1lenght + s2lenght + 1);
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	while (i < dstsize - dstlen - 1 && i < srclen)
	{
		dst[dstlen + i] = src [i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

int		ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (0);
	if (s[0] == (char)c)
		return (-1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slenght;
	char	*p;

	if (!s)
		return (0);
	slenght = ft_strlen(s);
	if (start >= slenght)
		return (ft_strdup(""/*, 0*/));
	if (slenght >= len)
		p = (char *)malloc(sizeof(char) * len + 1);
	else
		p = (char *)malloc(sizeof(char) * (slenght - start) + 1);
	if (!p)
		return (0);
	i = 0;
	while (i < len && i < slenght)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}