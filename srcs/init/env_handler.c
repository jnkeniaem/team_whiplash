/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:09:16 by jeekim            #+#    #+#             */
/*   Updated: 2022/10/03 16:09:17 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	make_g_env_array(char **envp)
{
	int		i;
	char	**env;

	i = 0;
	while (envp[i])
		++i;
	env = ft_calloc(i + 1, sizeof(char *));
	if (!env)
		system_call_error(ALLOC_FAIL);
	i = -1;
	while (envp[++i])
		env[i] = ft_strdup(envp[i]);
	g_env_array = env;
}
