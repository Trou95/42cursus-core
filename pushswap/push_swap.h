#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_size
{
    int *arr_a;
    int *arr_b;
    int *arr_c;
    size_t a_size;
    size_t b_size;
    int count;
}   t_psw;

int check_numbers(int ac,char** av);
int check_number(char* str, int* is_num);
int ft_error(char *s);

size_t ft_strlen(char* str);
int ft_atoi(char *s);

int    ft_allocatenumbers(t_psw *s);
void    ft_numprocess(t_psw *s, int ac, char **av, int index);
void    ft_putnumber(t_psw *s, char *str, int index);
int    check_samenum(int *s, int n, int index);

void ft_array_push(int* arr, size_t size, int value);
void ft_array_swap(int* arr, size_t size);
void ft_array_rotate(int* arr, size_t size);
void ft_array_revrotate(int* arr, size_t size);



int ft_check_order(t_psw *s);

void    indexing_numbers(t_psw *s);




#endif