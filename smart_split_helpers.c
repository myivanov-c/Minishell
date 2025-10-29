/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:09:29 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/29 12:15:43 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loperators.h"

int     is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

void    remove_spaces(char *str, size_t *i)
{
    while (str[*i] && is_space(str[*i]))
        (*i)++;
}

int     handle_operator_split(char *str, char **result, size_t *j, size_t *word_i)
{
    result[*word_i] = allocate_word(str, *j, *j + 2);
    if (!result[*word_i])
        return (0);
    (*word_i)++;
    *j += 2;
    return (1);
}

int     handle_word_split(char *str, char **result, size_t *j, size_t *word_i)
{
    size_t start;

    start = *j;
    while (is_not_delimiter(str, j))
        (*j)++;
    result[*word_i] = allocate_word(str, start, *j);
    if (!result[*word_i])
        return (0);
    (*word_i)++;
    return (1);
}

