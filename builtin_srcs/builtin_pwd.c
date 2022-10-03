/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:08:24 by jeekim            #+#    #+#             */
/*   Updated: 2022/10/03 16:08:46 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_pwd(char **args)
{
	char	path[PATH_MAX];

	(void)args;
	if (getcwd(path, PATH_MAX) == NULL)
	{
		set_or_get_status(errno);
		return ;
	}
	printf("%s\n", path);
	set_or_get_status(0);
}
