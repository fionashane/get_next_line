#include "get_next_line.h"

char *ft_add_chars(int fd, char *stat_str)
{
    char *buf_str;
    int rd_size;

    buf_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf_str)
        return (NULL);
    rd_size = 1;
    while (!ft_strchr(stat_str, '\n') && rd_size != 0)
    {
        rd_size = read(fd, buf_str, BUFFER_SIZE);
        if (rd_size == -1)
        {
            free(buf_str);
            return (NULL);
        }
        buf_str[rd_size] = '\0';
        stat_str = ft_strjoin(stat_str, buf_str);
    }
    free(buf_str);
    return (stat_str);
}

char *ft_gen_str(char *stat_str)
{
    char *return_str;
    int i;

    i = 0;
    if (!*stat_str)
        return (NULL);
    while (stat_str[i] && stat_str[i] != '\n')
        i++;
    return_str = (char *)malloc(sizeof(char) * (i + 2));
    if (!return_str)
        return (NULL);
    while (stat_str[i] && stat_str[i] != '\n')
    {
        return_str[i] = stat_str[i];
        i++;
    }
    if (stat_str[i] == '\n')
    {
        return_str[i] = stat_str[i];
        i++;
    }
    return_str[i] = '\0';
    return(return_str);
}

char *ft_remove_chars(char *stat_str)
{
    char *new_str;
    int i;
    int j;

    i = 0;
    while (stat_str[i] && stat_str[i] != '\n')
        i++;
    if (!stat_str[i])
    {
        free(stat_str);
        return (NULL);
    }
    new_str = (char *)malloc(sizeof(char) * (ft_strlen(stat_str) - i + 1));
    if (!new_str)
        return (NULL);
    i++;
    j = 0;
    while (stat_str[i])
        new_str[j++] = stat_str[i++];
    new_str[j] = '\0';
    free(stat_str);
    return (new_str);
}

char *get_next_line(int fd)
{
    char *return_str;
    static char *stat_str;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stat_str = ft_add_chars(fd, stat_str);
    if (!stat_str)
        return (NULL);
    return_str = ft_gen_str(stat_str);
    stat_str = ft_remove_chars(stat_str);
    return (return_str);
}

/*
char *get_next_line(int fd)
{
    char *buf;
    static char *st_buf[FD_MAX];
    char *ptr_nl;
    ssize_t rd_size;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (!(ptr_nl = ft_strchr(st_buf[fd], '\n')))
    {
        buf = (char *)malloc(BUFFER_SIZE + 1);
        if (!buf)
            return (NULL);
        rd_size = read(fd, buf, BUFFER_SIZE);
        if (rd_size <= 0)
            break;
        buf[rd_size] = '\0';
        st_buf[fd] = ft_strjoin_free(st_buf[fd], buf);
        free(buf);
        buf = NULL;
    }
    free(buf);
    line = ft_process_line(&st_buf[fd], ptr_nl);
    return(line);
}
*/