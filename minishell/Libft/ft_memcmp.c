/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:04:20 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 03:04:22 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (*((unsigned char *)s1 + idx) == *((unsigned char *)s2 + idx))
			idx++;
		else
			return ((*((unsigned char *)s1 + idx))
				- *((unsigned char *)s2 + idx));
	}
	return (0);
}
