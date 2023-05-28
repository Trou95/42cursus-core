/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:00:14 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/09 10:58:20 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_interpreter.h"

void	interpreter_qouete_init(const char *str, t_interpreter_quote *v)
{
	v->i = -1;
	v->env_len = 0;
	v->len = ft_strlen(str);
}

int	ft_set_envlen(int *env_len, int val)
{
	*env_len = val;
	return (val);
}
