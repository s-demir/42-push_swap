/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#             */
/*   Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#define GNL_BUF 42

static char	*gnl_strjoin(char *s1, char *s2, int len2)
{
	char	*res;
	int		len1;
	int		i;

	len1 = 0;
	if (s1)
		while (s1[len1])
			len1++;
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (free(s1), NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	i = -1;
	while (++i < len2)
		res[len1 + i] = s2[i];
	res[len1 + len2] = '\0';
	free(s1);
	return (res);
}

static char	*get_new_rest(char *rem, int i)
{
	char	*rest;
	int		len;
	int		j;

	len = 0;
	while (rem[i + len])
		len++;
	rest = malloc(len + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (j < len)
	{
		rest[j] = rem[i + j];
		j++;
	}
	rest[len] = '\0';
	return (rest);
}

static char	*extract_line(char **remainder)
{
	char	*line;
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while ((*remainder)[i] && (*remainder)[i] != '\n')
		i++;
	if ((*remainder)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = -1;
	while (++j < i)
		line[j] = (*remainder)[j];
	line[i] = '\0';
	rest = get_new_rest(*remainder, i);
	free(*remainder);
	*remainder = rest;
	return (line);
}

static int	has_newline(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buf[GNL_BUF];
	int			n;

	if (fd < 0)
		return (NULL);
	n = 1;
	while (!has_newline(remainder) && n > 0)
	{
		n = read(fd, buf, GNL_BUF - 1);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		remainder = gnl_strjoin(remainder, buf, n);
		if (!remainder)
			return (NULL);
	}
	if (!remainder || !remainder[0])
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	return (extract_line(&remainder));
}
