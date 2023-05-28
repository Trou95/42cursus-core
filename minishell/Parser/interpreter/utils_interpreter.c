/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_interpreter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirta <gdemirta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 09:45:15 by gdemirta          #+#    #+#             */
/*   Updated: 2022/10/09 09:45:32 by gdemirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_interpreter.h"

int	ft_is_valid_env(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '"' && str[i] != '\'' && \
		str[i] != ' ' && str[i] != '$')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (i);
}

int	ft_get_env_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '"' && str[i] != '\'')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			break ;
		i++;
	}
	return (i);
}

char	*ft_envjoin(char *dst, char *src)
{
	char	*n_str;

	if (dst == NULL || src == NULL)
		return (NULL);
	n_str = ft_strjoin(dst, src);
	free(dst);
	free(src);
	return (n_str);
}

int	ft_get_env(const char *str, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], str, ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}
