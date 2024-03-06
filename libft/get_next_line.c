/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:49:12 by gsims             #+#    #+#             */
/*   Updated: 2024/02/06 10:32:03 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Fills the line buffer
// Reads BUFFER_SIZE characters by iteration
// checks in each loop if there is data left in the leftover buffer
// If so it appends new read chars to it
// if not it duplicates the content of the read buffer to the leftover buffer
// if  \n is found it breaks from the loop
static char	*read_and_fill_buffer(int fd, char *leftover, char *buffer)
{
	ssize_t	read_line;
	char	*temp;

	read_line = 1;
	while (read_line > 0)
	{
		write(STDOUT_FILENO, "Inside GNL\n", 11);
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
	static char	*leftover;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(leftover);
		buffer = NULL;
		leftover = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_and_fill_buffer(fd, leftover, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftover = extract_line(line);
	return (line);
}
/*
int	main(void)
{
	int     fd;
	char    *line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		return (0);
	}
	// while()
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);


	//line = get_next_line(fd);
	//printf("end printf 5:%s\n", line);
	while ((line = get_next_line(fd)))
		printf("%s", line);
	return (0);
}*/
