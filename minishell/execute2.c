/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:23:23 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/10 02:25:46 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executer(t_syntax_tree *tree)
{
	if (tree->type == EXEC)
		voyage_on_tree(tree);
	else
	{
		voyage_on_tree(tree->left);
		if (tree->right->type == PIPE)
			executer(tree->right);
		else
			voyage_on_tree(tree->right);
	}
	catch_childs_exit();
}
