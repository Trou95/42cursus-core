/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksancako <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:27:30 by ksancako          #+#    #+#             */
/*   Updated: 2021/12/15 16:36:40 by ksancako         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtins.h"

int	ft_sort_params(char ***argv)
{
	int		i;
	int		f;
	char	*tmp;

	if (count_line(*argv) < 2)
		return (0);
	while (1)
	{
		i = 1;
		f = 1;
		while (argv[0][i] != 0)
		{
			if (ft_strncmp(argv[0][i - 1], argv[0][i], 100) > 0)
			{
				tmp = argv[0][i - 1];
				argv[0][i - 1] = argv[0][i];
				argv[0][i] = tmp;
				f = 0;
			}
			i++;
		}
		if (f)
			return (0);
	}
	return (0);
}
