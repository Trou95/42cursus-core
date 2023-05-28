/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:22:56 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 01:22:57 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtins.h"

int	command_pwd(void)
{
	int		exit;
	char	*str;

	exit = 0;
	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free(str);
	return (exit);
}
