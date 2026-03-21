#include "get_next_line_bonus.h"

static char	*correct_stash(char *stash)
{
	char	*correct_stash;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	correct_stash = malloc(ft_strlen(stash) - i + 1);
	if (!correct_stash)
		return (free(stash), NULL);
	i++;
	while (stash[i])
		correct_stash[j++] = stash[i++];
	correct_stash[j] = '\0';
	return (free(stash), correct_stash);
}

static char	*correct_line(char *stash)
{
	char	*line;
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

static char	*buffer_read(char *stash, int fd)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(stash, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
			return (free(stash), free(tmp), NULL);
		tmp[bytes] = '\0';
		stash = ft_strjoin(stash, tmp);
		if (!stash)
			return (free(tmp), NULL);
	}
	return (free(tmp), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	stash[fd] = buffer_read(stash[fd], fd);
	if (!stash[fd] || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = correct_line(stash[fd]);
	stash[fd] = correct_stash(stash[fd]);
	return (line);
}
