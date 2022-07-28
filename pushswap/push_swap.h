#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_data
{
    int *arr_a;
    int *arr_b;
    int *arr_c;
    size_t a_size;
    size_t b_size;
    size_t total_size;
}   t_data;

int ft_check_numbers(int ac,char** av);
int ft_check_number(char* str, int* is_num);
int ft_check_samenum(int *arr, int n, int index);
int ft_is_shorted(t_data *s);


int ft_error(char *s);

//
int    ft_init(t_data *p);

size_t ft_strlen(char* str);
void   ft_putstr(char* str);
int ft_atoi(char *str);

void    ft_numprocess(t_data *s, int ac, char **av, int index);
void    ft_putnumber(t_data *s, char *str, int index);


void ft_array_push(int* arr, size_t size, int value);
void ft_array_swap(int* arr, size_t size);
void ft_array_rotate(int* arr, size_t size);
void ft_array_revrotate(int* arr, size_t size);



int ft_array_numidx(t_data *p);
int ft_array_minidx(int *arr, size_t size, int start);


void    indexing_numbers(t_data *s);







#endif