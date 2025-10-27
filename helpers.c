/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:29:21 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/27 13:30:24 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     all_strings_empty(t_wildcard *w)
{
	int     i;

    i = 0;
	while (w->split_chars[i])
	{
		if (w->split_chars[i][0] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int     pattern_allows_hidden(t_wildcard *w)
{
	if (!w || !w->pattern)
		return (0);
	if (w->pattern[0] == '.')
        return (1);
    return (0);
}


void    append_matches(char ***filtered, char **matches)
{
	char	**temp;

	if (!*filtered)
		*filtered = matches;
	else
	{
		temp = append_arrays(*filtered, matches);
		free_array_split(matches);
		*filtered = temp;
	}
}
