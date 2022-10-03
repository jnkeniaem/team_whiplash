/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:43:18 by jeekim            #+#    #+#             */
/*   Updated: 2022/10/03 16:10:16 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

size_t	gnl_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*gnl_strchr(char *s, int c)
{
	int		i;
	size_t	len;

	i = 0;
	if (!s)
		return (0);
	len = gnl_strlen(s);
	while ((size_t)i < len + 1)
	{
		if (s[i] == (unsigned char) c)
			return (s + i);
		i++;
	}
	return (0);
}

size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = 0;
	return (gnl_strlen(src));
}

size_t	gnl_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = gnl_strlen(dst);
	if (dstsize >= len + 1)
	{
		i = 0;
		while (src[i] && i < dstsize - 1 - len)
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = 0;
		return (gnl_strlen(src) + len);
	}
	return (gnl_strlen(src) + dstsize);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (newstr == NULL)
		return (NULL);
	gnl_strlcpy(newstr, s1, s1_len + 1);
	gnl_strlcat(newstr + (s1_len), s2, s2_len + 1);
	free(s1);
	return (newstr);
}
