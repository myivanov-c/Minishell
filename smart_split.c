/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:59:08 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/30 17:22:33 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loperators.h"
#include "Wildcards/wildcards.h"

int     smart_array_size(char *str)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	remove_spaces(str, &i);
	while (str[i])
	{
		if (is_logical_operator(str, i))
			i += 2;
		else if (is_parenthesis(str[i]))
			i++;
		else
			skip_word(str, &i);
		count++;
		remove_spaces(str, &i);
	}
	return (count);
}

int     last_token_is_operator(char **res)
{
    int     i;

    i = 0;
    while (res[i])
        i++;
    if (i == 0)
        return (0);
    i--;
    if (ft_strcmp(res[i], "&&") == 0 || ft_strcmp(res[i], "||") == 0)
        return (1);
    return (0);
}

int     handle_token(char *str, char **res, size_t *j, size_t *w_i)
{
	if (str[*j] == '(' || str[*j] == ')')
	{
		res[*w_i] = allocate_word(str, *j, *j + 1);
		if (!res[*w_i])
			return (0);
		(*w_i)++;
		(*j)++;
		return (1);
	}
	if (is_logical_operator(str, *j))
		return (handle_operator_split(str, res, j, w_i));
	return (handle_word_split(str, res, j, w_i));
}

int     smart_loop(char *str, char **res)
{
	size_t	j;
	size_t	w_i;

	j = 0;
	w_i = 0;
	while (str[j])
	{
		remove_spaces(str, &j);
		if (!handle_token(str, res, &j, &w_i))
			return (free_array_n(res, w_i), 0);
	}
	res[w_i] = NULL;
	return (1);
}

char	**smart_split(char *str)
{
	char	**res;
    
    if (!str)
        return (NULL);
    res = malloc(sizeof(char *) * (smart_array_size(str) + 1));
    if (!res)
        return (NULL);
    if (!smart_loop(str, res))
        return (NULL);
    return (res);
}
