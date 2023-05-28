/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_redirection2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:35:43 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 02:36:11 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arger(char **cmd, int idx)
{
	if (is_redir(&cmd[0][idx]))
	{
		g_data.syntax_err = 1;
		return (0);
	}
	else if (cmd[0][idx] != ' ')
		return (1);
	return (0);
}
