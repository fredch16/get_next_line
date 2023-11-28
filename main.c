/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:34:34 by fcharbon          #+#    #+#             */
/*   Updated: 2023/11/21 17:43:50 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	gnl(int fd)
{
	char	*s;

	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = NULL;
}

int	main(void)
{
	int	fd;
	int	i;
	int	linecount;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	linecount = 5;
	while (i++ < linecount)
		gnl(fd);
	return (0);
}
