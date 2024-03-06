/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:59:28 by gsims             #+#    #+#             */
/*   Updated: 2023/11/15 10:32:01 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_and_fill_buffer(int fd, char *leftover, char *buffer)
{
	ssize_t	read_line;
	char	*temp;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
		{
			free(leftover);
			return (NULL);
		}
		else if (read_line == 0)
			break ;
		buffer[read_line] = 0;
		if (!leftover)
			leftover = ft_strdup("");
		temp = leftover;
		leftover = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

// reads leftover until \n or \0
// adds a \0 at the end of buffer
// returns substring of buffer from end of line to end of buffer
static char	*extract_line(char *buffer)
{
	unsigned int	i;
	char			*remaining_text;

	i = 0;
	if (buffer[0] == 0)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	remaining_text = ft_substr(buffer, i, ft_strlen(buffer));
	if (*remaining_text == 0)
	{
		free(remaining_text);
		remaining_text = NULL;
	}
	buffer[i] = '\0';
	return (remaining_text);
}

// Makes checks about fd
// Calls read_and_fill_buffer to get value of line variable
// free the buffer
// call extract_line function and store remaining value in static variable
// return line
char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*leftover[1024];

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(leftover[fd]);
		buffer = NULL;
		leftover[fd] = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_and_fill_buffer(fd, leftover[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftover[fd] = extract_line(line);
	return (line);
}
	/*
	int	main(void)
	{
		int     fd;
		int     fd2;
		char    *line;
		char    *line2;

		fd = open("test.txt", O_RDONLY);
		fd2 = open("test2.txt", O_RDONLY);
		while ((line = get_next_line(fd)) && (line2 = get_next_line(fd2)))
		{
			printf("%s", line);
			printf("%s", line2);
		}
		return (0);
	}*/
