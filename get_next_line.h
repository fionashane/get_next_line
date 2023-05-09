#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strdup(char *str);
char	*ft_strchr(const char *str, int32_t c);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *str, uint32_t start, size_t len);
int	ft_strlen(const char *str);

#endif