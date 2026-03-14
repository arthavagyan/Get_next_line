char	*get_next_line(int fd)
{
	ssize_t	n;
	char	*buf;
	
	n = read(fd, buf, BUFFER_SIZE);

}

