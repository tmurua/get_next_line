/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:39:26 by tmurua            #+#    #+#             */
/*   Updated: 2023/12/15 20:41:28 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Read the number of characters in the string */
size_t	ft_strlen(char *string)
{
	size_t	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

/* Find the \n or \0 */
char	*ft_strchr(char *string, int search_char)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	if (search_char == '\0')
		return ((char *)&string[ft_strlen(string)]);
	while (string[i] != '\0')
	{
		if (string[i] == (char)search_char)
			return ((char *)&string[i]);
		i++;
	}
	return (0);
}

/* Join everything to the end of the tmp_buffer variable */
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*store_str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	store_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (store_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			store_str[i] = s1[i];
	while (s2[j] != '\0')
		store_str[i++] = s2[j++];
	store_str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (store_str);
}
