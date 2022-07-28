#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_data
{
    int *arr_a;
    int *arr_b;
    int a_size;
    int b_size;
    int total_size;
}   t_data;

int ft_check_numbers(int ac,char** av);
int ft_check_number(char* str, int* is_num);
int ft_check_samenum(int *arr, int n, int index);
int ft_is_shorted(t_data *s);

void ft_array_numidx(t_data *p);
int ft_array_minidx(int *arr, size_t size, int start);

void ft_array_push(int* arr, int size, int value);
void ft_array_swap(int* arr, int size);
void ft_array_rotate(int* arr, int size);
void ft_array_revrotate(int* arr, int size);

void    ft_numprocess(t_data *s, int ac, char **av, int index);
void    ft_putnumber(t_data *s, char *str, int index);

int    ft_init(t_data *p);
int ft_error(char *s);

size_t ft_strlen(char* str);
void   ft_putstr(char* str);
int ft_atoi(char *str);












#endif