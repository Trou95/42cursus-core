/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:32:39 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/09 17:20:56 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser_utils.h"

int	ft_str_clearspace_end(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

char	*ft_str_clearspace(const char *str)
{
	int		i;
	char	*ret;
	char	*tmp;

	ret = ft_calloc(1, sizeof(char));
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			tmp = ft_substr(str, i, parser_quote_endidx(&str[i + 1], '"') + 2);
			i += ft_strlen(tmp);
			ret = ft_free_strjoin(ret, tmp);
		}
		else
		{
			tmp = ft_substr(str, i, 1);
			ret = ft_free_strjoin(ret, tmp);
			i += (str[i] != ' ') + ft_str_clearspace_end(&str[i]);
		}
		free(tmp);
	}
	return (ret);
}
