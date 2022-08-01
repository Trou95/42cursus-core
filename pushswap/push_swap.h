#ifndef _PUSH_SWAP_H
#define _PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
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
int ft_check_shorted(t_data *s);

void ft_array_numidx(t_data *p);
int ft_array_minidx(int *arr, size_t size, int start);
int ft_array_pivot(int *arr, int size);

void ft_array_push(int* arr, int size, int value);
void ft_array_swap(int* arr, int size);
void ft_array_rotate(int* arr, int size);
void ft_array_revrotate(int* arr, int size);

void ft_push(t_data *p, char check);
void ft_swap(t_data *p, char check);
void ft_rotate(t_data *p, char check);
void ft_revrotate(t_data *p, char check);

void ft_sort_pivot(t_data *p);
int ft_array_pivot(int* arr, int size);

int ft_sort_process(t_data *p);
int ft_sort_move(t_data *p, int index_a, int index_b);
void ft_sort_fnhook(int count, void(*fn)(t_data *, char), t_data *p, char check);

int ft_get_totalmove(t_data *p, int index, int *index_a);
int ft_get_movecount(int size, int index);

void    ft_numprocess(t_data *s, int ac, char **av, int index);
void    ft_putnumber(t_data *s, char *str, int index);

int ft_init(t_data *p);
int ft_atoi(char *str);
int ft_abs(int nb);
int ft_error(char *s);

size_t ft_strlen(char* str);
void   ft_putstr(char* str);


void ft_print(t_data *p);











#endif