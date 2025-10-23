/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:45:53 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:28:55 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen_gnl(const char *s)
{
    size_t  i;

    if (!s)
        return (0);
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strchr_gnl(const char *s, int c)
{
    int     i;

    i = 0;
    if (!s)
        return (NULL);
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return ((char *)(&s[i]));
        i++;
    }
    if ((char)c == '\0')
        return ((char *)(&s[i]));
    return (NULL);
}

char    *ft_strdup_gnl(const char *s)
{   
    char    *dup;
    size_t  i;
    size_t  dup_size;
    
    if (!s)
        return (NULL);
    dup_size = ft_strlen_gnl(s);
    dup = malloc(sizeof(char) * (dup_size + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char    *ft_substr_gnl(const char *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *sub;
    
    if (!s)
        return (NULL);
    if (start >= ft_strlen_gnl(s))
        return (ft_strdup_gnl(""));
    if (len > ft_strlen_gnl(s + start))
        len = ft_strlen_gnl(s + start);
    sub = malloc(sizeof(char) * (len + 1));
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}

char    *ft_strjoin_gnl(char *s1, const char *s2)
{
    char    *joined;
    size_t  i;
    size_t  j;
    size_t  len1;
    
    if (!s2)
        return (NULL);
    len1 = 0;
    if (s1)
        len1 = ft_strlen_gnl(s1);
    joined = malloc(sizeof(char) * (len1 + ft_strlen_gnl(s2) + 1));
    if (!joined)
        return (free (s1), NULL);
    i = 0;
    while (s1 && s1[i] != '\0')
    {
        joined[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2 && s2[j] != '\0')
        joined[i++] = s2[j++];
    joined[i] = '\0';
    free (s1);
    return (joined);
}