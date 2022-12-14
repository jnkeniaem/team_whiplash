/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redir_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:08:24 by jeekim            #+#    #+#             */
/*   Updated: 2022/10/01 16:08:25 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	e_dup2(int fd, int std)
{
	if (dup2(fd, std) == -1)
		system_call_error(errno);
	close(fd);
}

void	redir_action(t_node *cur_redir)
{
	char	*file_name;

	if (!cur_redir)
		return ;
	if (cur_redir->type == N_REDIR)
	{
		file_name = cur_redir->right->right->content;
		if (!ft_strncmp(cur_redir->right->content, "<", 2))
			open_redir_file(file_name, READ);
		else if (!ft_strncmp(cur_redir->right->content, ">", 2))
			open_redir_file(file_name, WRITE);
		else if (!ft_strncmp(cur_redir->right->content, ">>", 3))
			open_redir_file(file_name, APPEND);
	}
	redir_action(cur_redir->left);
}

void	open_redir_file(char *file, int mode)
{
	int	fd;

	if (mode == READ)
	{
		fd = open(file, O_RDONLY, 0777);
		if (fd == -1)
			system_call_error(errno);
		e_dup2(fd, STDIN_FILENO);
	}
	else if (mode == WRITE)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			system_call_error(errno);
		e_dup2(fd, STDOUT_FILENO);
	}
	else if (mode == APPEND)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (fd == -1)
			system_call_error(errno);
		e_dup2(fd, STDOUT_FILENO);
	}
}
