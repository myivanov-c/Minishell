/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:59:08 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/29 12:16:58 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loperators.h"

int     smart_array_size(char *str)
{
    size_t     i;
    int     word_count;

    i = 0;
    word_count = 0;
    remove_spaces(str, &i);
    while (str[i])
    {
        if ((str[i] == '&' && str[i + 1] == '&') ||
            (str[i] == '|' && str[i + 1] == '|'))
        {
            word_count++;
            i = i + 2;
        }
        else
        {
            word_count++;
            while (str[i] && !is_space(str[i]) &&
                   !(str[i] == '&' && str[i + 1] == '&') &&
                   !(str[i] == '|' && str[i + 1] == '|'))
                i++;
        }
        remove_spaces(str, &i);
    }
    return (word_count);
}

int     is_not_delimiter(char *str, size_t *j)
{
    if ((str[*j] && !is_space(str[*j]) &&
        !(str[*j] == '&' && str[*j + 1] == '&') &&
        !(str[*j] == '|' && str[*j + 1] == '|')))
            return (1);
    return (0);
}

char    *allocate_word(char *str, size_t start, size_t end)
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
        word[i] = str[start + i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

int     smart_loop(char *str, char **result)
{
    size_t  j;
    size_t  word_i;

    j = 0;
    word_i = 0;
    while (str[j])
    {
        remove_spaces(str, &j);
        if (str[j])
        {
            if ((str[j] == '&' && str[j + 1] == '&') ||
                (str[j] == '|' && str[j + 1] == '|'))
            {
                if (!handle_operator_token(str, result, &j, &word_i))
                    return (free_array_n(result, word_i), 0);
            }
            else
            {
                if (!handle_word_token(str, result, &j, &word_i))
                    return (free_array_n(result, word_i), 0);
            }
        }
    }
    result[word_i] = NULL;
    return (1);
}

char	**smart_split(char *str)
{
	char	**result;
    
    if (!str)
        return (NULL);
    result = malloc(sizeof(char *) * (smart_array_size(str) + 1));
    if (!result)
        return (NULL);
    if (!smart_loop(str, result))
        return (NULL);
    return (result);
}
