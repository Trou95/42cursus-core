/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:37:16 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/09 09:38:08 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser_utils.h"

char	*ft_strappend(char *dst, char c)
{
	size_t	len;
	char	*tmp;

	if (!dst)
		return (NULL);
	len = ft_strlen(dst);
	tmp = ft_calloc(len + 3, sizeof(char));
	tmp[0] = c;
	tmp[len + 1] = c;
	ft_memcpy(&tmp[1], dst, len);
	free(dst);
	return (tmp);
}
