#include "get_next_line.h"

int ft_check_errors(int fd)
{
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (1);
    return (0);
}

int ft_get_index(char *stash)
{
    int i;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    return (i);
}

static char    *ft_add_chars(int fd, char *stash)
{
    ssize_t        bytes_read;
    char        buffer[BUFFER_SIZE + 1];

    bytes_read = 0;
    if (!stash)
        stash = ft_strdup("");
    while (!ft_strchr(stash, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (!bytes_read)
            return (stash);
        if (bytes_read < 0)
            return (0);
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (!stash)
            return (0);
    }
    return (stash);
}

static char    *ft_gen_line(char *stash)
{
    int        i;
    char    *s;

    if (!stash)
        return (0);
    i = ft_get_index(stash);
    s = (char *)malloc(sizeof(char) * (i + 1));
    if (!s)
        return (0);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        s[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
    {
        s[i] = stash[i];
        i++;
    }
    s[i] = '\0';
    return (s);
}

char    *get_next_line(int fd)
{
    char        *aux;
    char        *line;
    static char    *stash;

    if (ft_check_errors(fd))
    {
        if (stash)
            free(stash);
        return (stash = 0);
    }
    stash = ft_add_chars(fd, stash);
    if (stash == 0 || *stash == 0)
    {
        free(stash);
        return (stash = 0);
    }
    line = ft_gen_line(stash);
    aux = ft_strchr(stash, '\n');
    if (aux && *aux)
        aux = ft_strdup(aux + 1);
    free(stash);
    stash = aux;
    return (line);
}