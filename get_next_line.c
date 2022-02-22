#include "get_next_line.h"

char* ft_retline(char** buf)
{
    char* ptr;
    int len;

    len = 0;
    while (*(*buf + len))
        if (*(*buf + len++) == '\n')
            break;
    if (len == 0)
        return (0);
    ptr = ft_strdup(*buf, len);
    *buf = ft_substr(*buf, len);
    return (ptr);
}

int ft_append(char* buf, char* tmpbuf, int bufsize, int fd)
{
    int size;

    size = read(fd, tmpbuf, bufsize);
    ft_strjoin(buf, tmpbuf, ft_strlen(tmpbuf));
    return (size);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char tmpbuf[BUFFER_SIZE + 1];
    int size;
    buffer = ft_resize(buffer);
    if (!buffer)
        return (0);
    size = read(fd, tmpbuf, BUFFER_SIZE);
    while (size > 0)
    {
        ft_strjoin(buffer, tmpbuf, ft_strlen(tmpbuf));
        if (ft_isnewline(buffer))
            break;
        buffer = ft_resize(buffer);
        size = read(fd, tmpbuf, BUFFER_SIZE);
    }
    int len = ft_isnewline(buffer) - buffer;
    return ft_retline(&buffer);
}