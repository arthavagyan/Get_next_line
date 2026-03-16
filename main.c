/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:31:33 by artavagy          #+#    #+#             */
/*   Updated: 2026/03/14 19:26:08 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	ssize_t	count;
	char	buf[7];
	int	fd;

	fd = open("test.txt", O_RDONLY);
	count = read(fd, buf, 6);
	buf[count] = '\0';
	printf("%s", buf);
	close(fd);
}
