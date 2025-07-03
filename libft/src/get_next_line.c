/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:05:39 by iazmi             #+#    #+#             */
/*   Updated: 2024/06/04 17:26:25 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Looks for new line index. -1 if not found
 * @param text string to scan.
 * @return index of new line || -1
 */
int	get_nl_index(char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/**
 * Function to call read.
 * Value array is always null terminated.
 * @param fd
 * @returns Bytes Read or -1 on Error
 */
int	reader_fn(int fd, char *value)
{
	int	bytes_read;

	bytes_read = read(fd, value, BUFFER_SIZE);
	if (bytes_read < 0)
		return (bytes_read);
	value[bytes_read] = '\0';
	return (bytes_read);
}

/**
 * Calls read, creates and expands buffer.
 * and will return 1 at EOF or error.
 * @param fd
 * @param buffer
 * @returns -1 if error, 0 if not EOF, 1 if EOF
 */
int	fill_buffer_fn(int fd, char **buffer)
{
	char	*value;
	int		bytes_read;

	value = (char *)malloc(BUFFER_SIZE + 1);
	if (value == NULL)
		return (-1);
	value[0] = '\0';
	bytes_read = reader_fn(fd, value);
	if (bytes_read < 0)
	{
		buffer_util(&value, 1);
		return (-1);
	}
	else if (bytes_read == 0)
	{
		*buffer = str_append_safe(*buffer, value);
		buffer_util(&value, 1);
		return (1);
	}
	*buffer = str_append_safe(*buffer, value);
	buffer_util(&value, 1);
	return (0);
}

/**
 * Conditions:
 * 1.) Slices string before found new line and alters buffer.
 * 2.) No new line found. Do nothing and return NULL.
 * 3.) No new line and EOF. Takes all letters and frees buffer.
 * @param buffer
 * @param eof
 * @returns String up to found new line.
 * String up to EOF.
 * NULL when new line not found.
 */
char	*parse_buffer(char **buffer, int eof)
{
	char	*line;
	char	*leftover;
	int		nl_index;

	nl_index = get_nl_index(*buffer);
	if (nl_index < 0 && eof == 1)
	{
		line = str_append_safe(NULL, *buffer);
		buffer_util(buffer, 1);
	}
	else if (nl_index >= 0)
	{
		leftover = str_append_safe(NULL, &(*buffer)[nl_index + 1]);
		(*buffer)[nl_index + 1] = '\0';
		line = str_append_safe(NULL, *buffer);
		buffer_util(buffer, 1);
		*buffer = leftover;
	}
	else
		line = NULL;
	return (line);
}

/**
 * @param fd file descriptor
 * @returns A string before found new line.
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	int			eof;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	buffer = buffer_util(&buffer, 0);
	line = NULL;
	eof = 0;
	while (!line)
	{
		if (eof != 1)
			eof = fill_buffer_fn(fd, &buffer);
		if (eof < 0 || buffer == NULL)
			return (NULL);
		else if (eof == 1 && buffer[0] == '\0')
		{
			buffer_util(&buffer, 1);
			line = NULL;
			break ;
		}
		buffer_util(&line, 1);
		line = parse_buffer(&buffer, eof);
	}
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int fd;
// 	char *value;
// 	int count;

// 	fd = open("test.txt", O_RDONLY);

// 	count = 0;
// 	value = get_next_line(fd);
// 	while (value != NULL)
// 	{
// 		printf("Count: %d -> %s", count, value);
// 		value = get_next_line(fd);
// 		count++;
// 	}
// 	free(value);
// }