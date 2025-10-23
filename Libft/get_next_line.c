/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:32:11 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:28:07 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_and_append(int fd, char *stash)
{
    char    *buf;
    ssize_t bytes;

    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (free(stash), NULL);
    bytes = 1;
    while (!ft_strchr_gnl(stash, '\n') && bytes > 0)
    {
        bytes = read(fd, buf, BUFFER_SIZE);
        if (bytes == -1)
            return (free(buf), free(stash), NULL);
        buf[bytes] = '\0';
        stash = ft_strjoin_gnl(stash, buf);
        if (!stash)
            return (free(buf), NULL);
    }
    free(buf);
    return (stash);
}

static char     *extract_line(char *stash)
{
    size_t  i;
    
    if (!stash[0])
        return (NULL);
    i = 0;
    while (stash[i] != '\0' && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    return (ft_substr_gnl(stash, 0, i));
}
static char     *clean_stash(char *stash)
{
    char    *new_stash;
    size_t  i;
    
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
char    *get_next_line(int fd)
{
    static char     *stash;
    char            *line;

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
        free (stash);
        stash = NULL;
        return (NULL);
    }
    stash = clean_stash(stash);
    return (line);
}