/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:33:45 by jeekim            #+#    #+#             */
/*   Updated: 2022/10/03 16:10:18 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*for_next(char *save)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (gnl_strlen(save) - i));
	if (!str)
		return (NULL);
	j = 0;
	while (save[i + 1])
	{
		str[j] = save[i + 1];
		j++;
		i++;
	}
	str[j] = 0;
	free (save);
	return (str);
}

char	*rtg(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*read_and_save(int fd, char *save)
{
	char	*buf;
	int		rd;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	while (!gnl_strchr(save, '\n') && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[rd] = 0;
		save = gnl_strjoin(save, buf);
	}
	free (buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = rtg(save);
	save = for_next(save);
	return (line);
}
/*
#include <fcntl.h>

int main ()
{
	open(a.txt, O_RDONLY);
	printf(%s)
}
*/