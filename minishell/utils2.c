/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:27:04 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 01:27:26 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirection	*ft_lstlast_redir(t_redirection *redir)
{
	if (redir == NULL)
		return (0);
	while (redir->next != NULL)
		redir = redir->next;
	return (redir);
}

void	ft_lstadd_back_redir(t_redirection **redir, t_redirection *new)
{
	if (redir && new)
	{
		if (!*redir)
			*redir = new;
		else
			ft_lstlast_redir(*redir)-> next = new;
	}
}
