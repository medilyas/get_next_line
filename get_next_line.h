#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_strlcat(char *dst, const char *src, size_t dstlen, size_t srclen);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(char	*s1, char	*s2);
char	*ft_free(char *s);


#endif