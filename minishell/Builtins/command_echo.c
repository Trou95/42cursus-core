/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:25:39 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 01:25:40 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtins.h"

int	command_echo(char **str)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	while (str[++i] && !ft_strncmp(str[i], "-n", 3))
		check = 0;
	while (str[i])
		printf("%s ", str[i++]);
	if (check)
		printf("\n");
	return (0);
}
