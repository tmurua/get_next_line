/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tmurua@student.42berlin.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:17:52 by tmurua            #+#    #+#             */
/*   Updated: 2023/12/27 22:01:48 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_concatenate_line(int fd, char *left_c, char *buffer);
static char	*set_leftover_chars(char *current_line);

/* Get the next line from the file descriptor (fd)
* left_c are leftover chars from previous call
* Allocates mem for buffer, checks invalid fd, buffer size or read error
* Checks for buffer allocation failure
* Reads line from fd and concatenate with any leftover chars
* Update left_c with remaining chars after \n for the next call
* Returns the concatenated line, including any left_c */
char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*current_line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	current_line = read_concatenate_line(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!current_line)
		return (NULL);
	left_c = set_leftover_chars(current_line);
	return (current_line);
}

/* Read the current line from the fd and concatenate it with any left_c
* Initialize bytes_read to 1 to enter the loop
* Read chars from fd into buffer and assign to bytes_read
* free left_c in case of error, if nothing is read break out of the loop
* Null-terminate the buffer, to treat it as str  and check if left_c is empty
* Concatenate the current buffer with left_c
* Check if a \n is present in the buffer, exiting the loop if yes
* Return the concatenated string */
static char	*read_concatenate_line(int fd, char *left_c, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

/* Set left_c by extracting remaining chars after a \n in the line
* Find the position of \n or the end of the str, \0
* Check for an empty line or end of file after the \n
* Set left_c to the substring after the \n
* Check if left_c is empty, if so free left_c
* Null-terminate current_line after \n
* Return remaining substring (left_c) after the \n */
static char	*set_leftover_chars(char *current_line)
{
	ssize_t	i;
	char	*left_c;

	i = 0;
	while (current_line[i] != '\n' && current_line[i] != '\0')
		i++;
	if (current_line[i] == 0 || current_line[1] == 0)
		return (NULL);
	left_c = ft_substr(current_line, i + 1, ft_strlen(current_line) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	current_line[i + 1] = 0;
	return (left_c);
}
