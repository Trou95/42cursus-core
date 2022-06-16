#ifndef _UTILS_H
#define _UTILS_H

#ifdef _WIN32
#include <io.h>
#define write() _write()
#else
#include <unistd.h> 
#endif

#include <stdio.h>
#include <limits.h>






typedef struct s_list
{
	int* arr_a;
	int* arr_b;
}
	t_list;


int	ft_isdigit(char c);
size_t	ft_strlen(char* str);
int	ft_strncmp(char* str, char* str2, int len);
long long	ft_atoi(const char* str);

t_list*	ft_util_initlist(t_list* list);

void	ft_check_numbers(int ac, char** av);
int ft_check_number(char* str, int* i, int* bIsDigit, int type);

int ft_util_msg(char* msg);





#endif