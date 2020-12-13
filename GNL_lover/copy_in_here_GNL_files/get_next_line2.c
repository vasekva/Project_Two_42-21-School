
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int 	get_next_line(int fd, char **line);

void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *to, const char *from);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *destination, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif