/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:15:39 by fcharbon          #+#    #+#             */
/*   Updated: 2023/11/29 21:15:46 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h> 

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			read_result;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (buffer_total_clear(fd, (char **) buffer, line));
	while (1)
	{
		if (buffer[fd][0] == '\0')
		{
			read_result = read(fd, buffer[fd], BUFFER_SIZE);
			if (read_result == -1)
				return (buffer_total_clear(fd, NULL, line));
			if (read_result == 0)
				return (line);
		}
		flag = line_updater(&line, buffer[fd]);
		buffer_clear(buffer[fd]);
		if (flag == 1)
			return (line);
		if (flag == -1)
			return (NULL);
	}
}

// int main(void) 
// {
//     int fds[2];
//     char *lines[2];

//     fds[0] = open("file1.txt", O_RDONLY);
//     fds[1] = open("file2.txt", O_RDONLY);
//     while ((lines[0] = get_next_line(fds[0])) != NULL) 
// 	{
//         printf("line: %s\n", lines[0]);
//         free(lines[0]);
//     }
//     while ((lines[1] = get_next_line(fds[1])) != NULL)
// 	{
//         printf("line: %s\n", lines[1]);
//         free(lines[1]);
//     }    
//     close(fds[0]);
//     close(fds[1]);
//     return (0);
// }

/*int main(void)
{
    char    *line;
    int     fd1;

    fd1 = open("myfile.txt", O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error opening file");
        return (1);
    }
        while ((line = get_next_line(fd1)) != NULL)
        {
            printf("line; %s", line);
            free(line);
        }
    close(fd1);
    return (0);
}*/
