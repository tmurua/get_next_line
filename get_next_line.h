/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:10:05 by tmurua            #+#    #+#             */
/*   Updated: 2023/12/15 20:16:56 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* Defining buffer size */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

/* Helper functions */
size_t	ft_strlen(char *string);
char	ft_strchr(char *string, int search_char);
char	ft_strjoin(char *s1, char *s2);

/* Main functions */
char	*ft_read(int fd, char *tmp_save);
char	*get_next_line(int fd);
char	*ft_getline(char *read);
char	*ft_free_buffer(char *buffer);

#endif
