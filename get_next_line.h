#ifndef GNL_H
#define GNL_H

#include <stdlib.h>
#include <fcntl.h>

//

#include <stdio.h>
#include <string.h>

#include <errno.h>

#define BUFFER_SIZE 10

//

char    *get_next_line(int fd);
char    *ft_isnewline(char *str);

char *ft_resize(char *buf);

char *ft_substr(char *str, int index);
char *ft_strdup(char *str, int index);

size_t ft_strlen(const char *str);
char *ft_strjoin(char *dest, const char *src,int size);


#endif