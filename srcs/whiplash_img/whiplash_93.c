/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whiplash_93.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jujeon <jujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:45:35 by jeekim            #+#    #+#             */
/*   Updated: 2022/10/11 13:12:28 by jujeon           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	whiplash_img(void)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(
			"./srcs/whiplash_img/whiplash_93",
			O_RDONLY);
	i = 0;
	while (i < 50)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		i++;
	}
	printf("\n");
}
