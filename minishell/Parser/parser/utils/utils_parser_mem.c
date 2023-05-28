/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser_mem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:29:18 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/09 09:29:26 by gdemirta         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "parser_utils.h"

char	*ft_free(char *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

char	**ft_double_free(char **ptr, size_t size)
{
	size_t	i;

	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (ptr[i])
			free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}
