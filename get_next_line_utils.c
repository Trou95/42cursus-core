#include "get_next_line.h"


char *ft_isnewline(char *str)
{
    int i;

    i = 0;
    if (!str)
        return 0;
    while(str[i])
    {
        if(str[i] == '\n')
            return (&str[i]);
        i++;
    }
    return 0;
}

char *ft_substr(char *str,int index)
{
    char *ptr;
    int i;

    ptr = malloc(ft_strlen(str) + 1);
    if(!ptr)
        return(0);
    i = 0;
    while(str[i])
    {
        ptr[i] = str[index + i];
        i++; 
    }
    ptr[i] = '\0';
    return ptr;
}

size_t ft_strlen(const char *buf)
{
    size_t i;
    if(!buf)
        return 0;
    i = 0;
    while(buf[i])
        i++;
    return i;
}

char *ft_resize(char *buf)
{
    char *ptr;
    int len;
    int i;

    len = ft_strlen(buf) + BUFFER_SIZE;
    ptr = malloc(len + 1);
    if(!ptr)
        return 0;
    i = 0;
    if (buf)
    {
        while (i < len + 1)
        {
            if (buf[i])
                ptr[i++] = buf[i];
            else
            {
                ptr[i++] = '\0';
                break;
            }
        }
        ptr[i] = '\0';
        free(buf);
    }
    else ptr[0] = '\0';
    return ptr;
}

char *ft_strdup(char *str, int len)
{
    char *ptr;
    int i;
    if (!str || len <= 0 || ft_strlen(str) < len)
        return 0;
    ptr = (char *)malloc(sizeof(char) * (len + 1));
    if(!ptr)
        return 0;
    i = 0;
    while(i < len)
    {
        ptr[i] = str[i];
        i++;
    }
    ptr[i] = '\0';
    return ptr;
}

char *ft_strjoin(char *dest, const char *src,int size)
{
    size_t len;
    size_t i;

    len = ft_strlen(dest);
    i = 0;
    while(src[i] > 0 && i < size)
    {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0'; 
    return dest;
}