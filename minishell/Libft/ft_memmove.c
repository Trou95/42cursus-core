/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:04:13 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 03:04:15 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t	i;

	if (dest == src || !num)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (i < num)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		while (num)
		{
			*((char *)(dest + num) - 1) = *((char *)src + num - 1);
			num--;
		}	
	}
	return (dest);
}
