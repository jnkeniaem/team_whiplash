/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:10:31 by jeekim            #+#    #+#             */
/*   Updated: 2022/10/03 16:10:32 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_traverse(t_node *node)
{
	const char	*token_str[8]
		= {"NONE", "T_WORD", "T_PIPE", "T_REDIR", "T_HEREDOC", "N_REDIR",
		"N_PHRASE", "N_PROCESS"};

	if (!(node))
		return ;
	if (node)
		printf("current node->type : [%s]\n", token_str[node->type]);
	if (node->content)
		printf("current node->content : [%s]\n", node->content);
	printf("before move\n");
	ft_traverse(node->left);
	ft_traverse(node->right);
}
