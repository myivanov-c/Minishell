/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:44:31 by myivanov          #+#    #+#             */
/*   Updated: 2025/12/01 20:47:06 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_append(int fd, char *stash)
{
	ssize_t	bytes;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(stash), NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr_gnl(stash, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free (buf), free (stash), (NULL));
		buf[bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
		if (!stash)
			return (free (buf), (NULL));
	}
	free (buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr_gnl(stash, 0, i);
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*new_stash;
	size_t	i;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	new_stash = ft_strdup_gnl(&stash[i]);
	free (stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = ft_strdup_gnl("");
		if (!stash)
			return (NULL);
	}
	stash = read_and_append(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
