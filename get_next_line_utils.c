#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *str;
    size_t  size;
    int     i;
    int     j;

    size = ft_strlen(s1) + ft_strlen(s2) + 1;
    str = (char *)malloc(size * sizeof(char));
    if (!str)
        return (0);
    i = 0;
    j = 0;
    while (s1[j])
        str[i++] = s1[j++];
    j = 0;
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
	free(s1);
    return (str);
}

char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if ((unsigned char)*s == (unsigned char)c)
            return ((char *)s);
        s++;
    }
    if (!c)
        return ((char *)s);
    return (0);
}

char    *ft_strdup(const char *s)
{
    char    *dup;
    int     i;

    i = 0;
    dup = (char *)malloc(ft_strlen(s) + 1);
    if (!dup)
        return (0);
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}