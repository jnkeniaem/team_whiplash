/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:08:20 by jeekim            #+#    #+#             */
/*   Updated: 2022/10/01 16:29:51 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	e_execve(char *path, char **args)
{
	if (opendir(path))
	{
		printf("-whiplash: %s: Is a directory\n", path);
		return ;
	}
	if (execve(path, args, g_env_array) == -1)
		system_call_error(errno);
}

char	**lst_to_2d_array(t_node *arg)
{
	char	**ptr;
	int		size;
	int		i;

	size = ft_lstsize(arg);
	i = -1;
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (NULL);
	while (++i < size)
	{
		ptr[i] = ft_strdup(arg->content);
		arg = arg->right;
	}
	ptr[i] = NULL;
	return (ptr);
}

void	cmd_action_init(
	t_node *cur_cmd, char ***p_args, int *p_func_idx, int old_stdin)
{
	*p_args = lst_to_2d_array(cur_cmd);
	*p_func_idx = is_builtin_func(cur_cmd);
	if (*p_func_idx < 0)
		e_dup2(old_stdin, STDIN_FILENO);
}

void	cmd_action(
	t_node *cur_cmd,
	t_func_type builtin[],
	int old_stdin)
{
	char		*path;
	char		**args;
	int			func_idx;
	struct stat	statbuf;

	cmd_action_init(cur_cmd, &args, &func_idx, old_stdin);
	if (func_idx > -1)
		run_builtin(cur_cmd, builtin, func_idx, old_stdin);
	else if (is_absolute_path(cur_cmd->content)
		|| is_relative_path(cur_cmd->content))
	{
		if (stat(cur_cmd->content, &statbuf) == -1)
			cmd_not_found_error(cur_cmd);
		e_execve(cur_cmd->content, args);
	}
	else
	{
		path = search_path(cur_cmd->content);
		if (!path)
			path = no_search_path(cur_cmd, args, cur_cmd->content);
		if (path)
			e_execve(path, args);
	}
	free_2d(args);
}
