/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_return_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:44:33 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 03:00:03 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_interpreter.h"

char	*ft_retvalue(int value)
{
	int		i;
	int		val;
	char	*ret;

	ret = ft_calloc(5, sizeof(char));
	i = 0;
	if (value < 0)
	{
		ret[i++] = '-';
		value = -value;
	}
	val = value;
	while (val)
	{
		val /= 10;
		i++;
	}
	while (value)
	{
		ret[--i] = value % 10 + '0';
		value /= 10;
	}
	return (ret);
}
