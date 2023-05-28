/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_qouteend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:35:42 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 02:38:18 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser_utils.h"

int	ft_get_qoueteend(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i += parser_quote_endidx(&str[i + 1], c);
		else if (str[i] == ' ')
			break ;
		else if (str[i])
			i++;
	}
	return (i);
}
