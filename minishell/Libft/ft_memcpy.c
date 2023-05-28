/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:04:15 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 03:04:18 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t	i;

	if (dest == src || !num)
		return (dest);
	i = 0;
	while (i < num)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}
