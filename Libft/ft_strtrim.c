/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:05:50 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/22 12:02:15 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int     ft_is_in_set(char c, const char *set)
{
    size_t  i;

    i = 0;
    while (set[i] != '\0')
    {
        if (set[i] == c)
        {
            return (1);
        }
        i++;
    }
    return (0);
}

static void     ft_copy_trimeed(char *dest, const char *s, size_t start, size_t end)
{
    size_t  i;

    i = 0;
    while (start < end)
    {
        dest[i] = s[start];
        i++;
        start++;
    }
    dest[i] = '\0';
}

static void     ft_get_trimmed_indices(const char *s, const char *set, size_t *start, size_t *end)
{
    *start = 0;
    *end = ft_strlen(s);
    while (s[*start])
    {
        if (ft_is_in_set(s[*start], set))
            (*start)++;
        else
            break ;
    }
    while (*end > *start)
    {
        if (ft_is_in_set(s[*end - 1], set))
            (*end)--;
        else
            break ;
    }
}

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    char    *trimmed;

    if (!s1 || !set)
		return (NULL);
    ft_get_trimmed_indices(s1, set, &start, &end);
    trimmed = (char *)malloc((end - start) + 1);
    if (!trimmed)
        return (NULL);
    ft_copy_trimeed(trimmed, s1, start, end);
    return (trimmed);
}

/*int     main(void)
{
    char    *s1 = "-----Ferrari SF25-----Bugatti++-----";
    char    *set = "-+Bugatti";
    char    *trimmed;

    trimmed = ft_strtrim(s1, set);
    if (!trimmed)
    {
        printf("Falha ao alocar memória.\n");
    }
    else
    {
        printf("%s\n", trimmed);
    }
    free (trimmed);
    return (0);
}*/