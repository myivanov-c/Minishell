/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:02:31 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/23 17:31:56 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t  ft_word_count(char const *s, char c)
{
    size_t  i;
    size_t  count;

    i = 0;
    count = 0;
    while (s[i] != '\0')
    {
        if (s[i] != c && (i == 0 || s[i - 1] == c))
        {
            count++;
        }
        i++;
    }
    return (count);
}

static char *ft_malloc_word(const char *s, size_t start, size_t end)
{
    size_t  len;
    size_t  i;
    char    *word;

    len = end - start;
    word = (char *)malloc(len + 1);
    if (!word)
        return (NULL);
    i = 0;
    while (i < len)
    {
        word[i] = s[start + i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

static void     ft_free_all(char **array, size_t words)
{
    size_t i;
    
    i = 0;
    while (i < words)
    {
        free (array[i]);
        i++;
    }
    free (array);
}

static int  ft_split_loop(char const *s, char c, char **result)
{
    size_t  i;
    size_t  word_i;
    size_t  start;

    i = 0;
    word_i = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            start = i;
            while (s[i] && s[i] != c)
                i++;
            result[word_i] = ft_malloc_word(s, start, i);
            if (!result[word_i])
                return (ft_free_all(result, word_i), 0);
            word_i++;
        }
    }
    result[word_i] = NULL;
    return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
    
    if (!s)
        return (NULL);
    result = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
    if (!result)
        return (NULL);
    if (!ft_split_loop(s, c, result))
        return (NULL);
    return (result);
}

/*int     main(void)
{
    char     **array;
    size_t  i;

    i = 0;
    array = ft_split("---Bugatti Chiron Supper Sport--Daytona SP3---Aston Martin Valkyrie---Koenigsegg CC850-", '-');
    while (array[i])
    {
        printf("Word:%zu: %s\n", i, array[i]);
        i++;
    }
    i = 0;
    while (array[i])
    {
        free (array[i]);
        i++;
    }
    free (array);
    return (0);
}*/