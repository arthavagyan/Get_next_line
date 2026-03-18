/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:29:13 by artavagy          #+#    #+#             */
/*   Updated: 2026/03/18 17:06:24 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*buffer_read(int fd, char *stash)
{
	char	*tmp;
	ssize_t	bytes;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = '\0';
		stash = ft_strjoin(stash, tmp);
	}
	return (stash);
}

static char	*correct_line(char *stash, char *line)
{
	size_t	i;

	i = 0;
	if (!stash || !stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*correct_stash(char *stash)
{
	char	*correct_stash;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	correct_stash = malloc(ft_strlen(stash) - i + 1);
	if (!correct_stash)
		return (NULL);
	i++;
	while (stash[i])
		correct_stash[j++] = stash[i++];
	correct_stash[j] = '\0';
	free(stash);
	return (correct_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = buffer_read(fd, stash);
	if (!stash)
		return (NULL);
	line = correct_line(stash, line);
	stash = correct_stash(stash);
	return (line);
}
