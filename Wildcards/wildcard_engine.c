/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_engine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:31:25 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/28 10:24:27 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

int     calculate_size_of_new_array(char **original, char **to_append)
{
    int     count_ori;
    int     count_ap;
    int     size;
    
    count_ori = 0;
    count_ap = 0;
    while (original[count_ori] != NULL)
        count_ori++;
    while (to_append[count_ap] != NULL)
        count_ap++;
    size = count_ori + count_ap;
    return (size);
}

void    copy_original(char **original, char **new_array, int *i)
{
    size_t  j;
    size_t  len;
    int     k;

    k = 0;
    while (original[k] != NULL)
    {
        len = ft_strlen(original[k]);
        new_array[*i] = malloc(sizeof(char) * (len + 1));
        if (!new_array[*i])
            return ;
        j = 0;
        while (j < len)
        {
            new_array[*i][j] = original[k][j];
            j++;
        }
        new_array[*i][j] = '\0';
        (*i)++;
        k++;
    }
}

void    copy_append(char **to_append, char **new_array, int *i)
{
    size_t  len;
    size_t  j;
    int     k;

    k = 0;
    while (to_append[k] != NULL)
    {
        len = ft_strlen(to_append[k]);
        new_array[*i] = malloc(sizeof(char) * (len + 1));
        if (!new_array[*i])
            return ;
        j = 0;
        while (j < len)
        {
            new_array[*i][j] = to_append[k][j];
            j++;
         }
        new_array[*i][j] = '\0';
        (*i)++;
        k++;
    }
}

char    **append_arrays(char **original, char **to_append)
{
    int     size;
    char    **new_array;
    int     i;

    i = 0;
    size = calculate_size_of_new_array(original, to_append);
    new_array = malloc(sizeof(char *) * (size + 1));
    if (!new_array)
        return (NULL);
    copy_original(original, new_array, &i);
    copy_append(to_append, new_array, &i);
    new_array[i] = NULL;
    free_array_split (original);
    return (new_array);
}

char	**wildcard_engine(char **args)
{
	char	**filtered;
	char	**matches;
	int		i;

	i = 0;
	filtered = NULL;
	while (args[i])
	{
		if (check_presence_of_wildcard(args[i]))
		{
			matches = total_filtered_outcomes_multi(args[i]);
			if (!matches)
				return (free_array_split(filtered), NULL);
			append_matches(&filtered, matches);
		}
		i++;
	}
	return (filtered);
}

