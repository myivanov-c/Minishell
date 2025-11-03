/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_small_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:20:36 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/30 17:36:26 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loperators.h"
#include "Wildcards/wildcards.h"

int     is_parenthesis(char c)
{
	return (c == '(' || c == ')');
}

void	skip_word(char *str, size_t *i)
{
	while (str[*i] && !is_space(str[*i])
		&& !is_logical_operator(str, *i)
		&& !is_parenthesis(str[*i]))
		(*i)++;
}

int     is_not_delimiter(char *str, size_t i)
{
	if (!str[i])
		return (0);
	if (is_space(str[i]))
		return (0);
	if ((str[i] == '&' && str[i + 1] == '&')
		|| (str[i] == '|' && str[i + 1] == '|'))
		return (0);
	if (str[i] == '(' || str[i] == ')')
		return (0);
	return (1);
}

char    *allocate_word(char *str, size_t start, size_t end)
{
    size_t  len;
    size_t  i;
    char    *word;

    len = end - start;
    if (len == 0)
        return (NULL);
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
