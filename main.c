#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	ssize_t	count;
	char	buf[6];
	int	fd;

	fd = open("test.txt", O_RDONLY);
	count = read(fd, buf, 5);
	buf[count] = '\0';
	printf("%s", buf);
	close(fd);
}
