/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:38:13 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/22 16:02:15 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     check_presence_of_wildcard_pre(char *str)
{
    int     i;
    int     result;

    i = 0;
    result = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '*')
            result = 1;
        i++;
    }
    return (result);
}

int     filter_data_size_pre(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '*')
        i++;
    return (i);
}

char    *store_wildcard_pre(char *str)
{
    char    *filter;
    int     size;
    int     i;

    size = filter_data_size_pre(str);
    filter = malloc(sizeof(char) * (size + 1));
    if (!filter)    
        return (NULL);
    i = 0;
    while (i < size)
    {
        filter[i] = str[i];
        i++;
    }
    filter[i] = '\0';
    return (filter);
}

int     check_if_file_valid_pre(char *line_to_compare, int f_size, char *f_data)
{
    
}

int     main(int argc, char **argv)
{
    if (argc < 2)
        return (0);

    int     count;
    char    *stored;

    if (!check_presence_of_wildcard_pre(argv[1]))
        return (0);
    count = filter_data_size_pre(argv[1]);
    printf("%d\n", count);
    stored = store_wildcard_pre(argv[1]);
    printf("Stored: %s\n", stored);
    free (stored);
    return (0);
}