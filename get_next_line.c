#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char *ft_add_chars(int fd, char *line, char *buffer)
{
    ssize_t rd_size;

    rd_size = BUFFER_SIZE;
    while (!(ft_strchr(buffer, '\n')) && rd_size == BUFFER_SIZE)
    {
        rd_size = read(fd, buffer, BUFFER_SIZE);
        buffer[rd_size] = '\0';
        if (rd_size <= 0 && !line[0])
        {
            free(line);
            line = NULL;
            return (NULL);
        }
        line = ft_strjoin(line, buffer);
    }
    return (line);
}

static char *ft_remove_chars(char *line, char *buffer)
{
    ssize_t i;
    ssize_t j;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
	if (line[i] == '\n')
        i++;
    j = (ft_strlen(line) - i);
    if (j != 0)
        ft_strlcpy(buffer, line + i, j + 1);
    else
        buffer[0] = '\0';
    return (ft_substr(line, 0, i + 1));
}

char *get_next_line(int fd)
{
    char *line;
    static char buffer[BUFFER_SIZE + 1];

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    line = malloc(1);
    if (!line)
        return (0);
    line[0] = '\0';
    if (buffer[0] != '\0')
        line = ft_strjoin(line, buffer);
    line = ft_add_chars(fd, line, buffer);
    if (!line)
        return (0);
    return (ft_remove_chars(line, buffer));
}