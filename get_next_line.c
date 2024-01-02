/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tmurua@student.42berlin.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:17:52 by tmurua            #+#    #+#             */
/*   Updated: 2024/01/02 18:23:50 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_concatenate_line(int fd, char *left_c, char *buffer);
static char	*set_leftover_chars(char *current_line);

/*char		*get_next_line(int fd);
#include <stdio.h>

int	main(void)
{
	int			fd;
	char	*line;

	fd = open("41_with_nl", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
}
*/
/* left_c: remaining chars from previous call (static char)
buffer: temp storage for chars being read now in the fd
allocate mem for buffer, check invalid fd, buffer size or read error
check buffer allocation failure,
current_line: concatenate buffer with left_c from previous call
Update left_c with remaining chars after /n for the next call
Return the concatenated line, including any left_c
 */
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

/* Initialize bytes_read to 1 to enter the loop for 1st time
read chars from fd into buffer and assign number of bytes read to bytes_read
when doing so, it also changes value of str buffer with content from file
free left_c in case of error, if nothing is read break out of the loop
buffer[bytes_read]: buffer[last char of str buffer] = 0 to null terminate str
left_c wasn’t initialize in first loop, so assign empty str to it
join str tmp (clone of left_c atm) with str buffer. 1st time: left_c=buffer
search for \n in buffer, if \n not found on buffer, restart loop
if found break loop and return left_c, i.e. current_line = left_c
*/
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

/* Increment current_line until \n or end of str found, i = this position
Check for empty line or end of file after the \n, if so return NULL
Set left_c to substring after the \n to use next time we use get_next_line
Check if left_c is empty, if so free left_c
Null-terminate current_line after \n, it’ll be the final return in get_next_line
Return remaining substring (left_c) after the \n assigning it to left_c in get_n_l
*/
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
