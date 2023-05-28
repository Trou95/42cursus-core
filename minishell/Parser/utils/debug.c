/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:37:59 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 02:38:00 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	array_cleaner(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	array_writer(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("str[%d] => %s\n", i, arr[i]);
		i++;
	}
}
