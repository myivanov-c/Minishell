/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:39:11 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/22 22:08:52 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     scan_argument(char *str)
{
    int     i;
    int     sufix_md;

    sufix_md = 0;
    i = 0;
    while (str[i] != '*')
        i++;
    if (str[i] == '*' && str[i + 1] != '\0')
    {
        sufix_md = 1;
        return (sufix_md);
    }
    else if (str[i] == '*' && str[i + 1] == '\0')
        sufix_md = 0;
    return (sufix_md);
}

void     sufix_mode(char *str)
{
    int     size;
    int     start = 0;
    char    *filter_data;
    struct dirent *entry = NULL;
    char    **dest;
    int     i;
    
    size = filter_data_size_su(str, &start);
    filter_data = store_whats_after_wildcard_su(str, start);
    dest = total_filtered_outcomes_sufix(entry, size, filter_data);
    i = 0;
    while (dest[i] != NULL)
    {
        printf("What I have in dest is: %s\n", dest[i]);
        i++;
    }
}

void    prefix_mode(char *str)
{

    int     count;
    char    *stored;
    struct dirent *entry = NULL;
    int     i;
    char    **dest;

    count = filter_data_size_pre(str);
    stored = store_wildcard_pre(str);
    dest = total_filtered_outcomes_pre(entry, count, stored);
    i = 0;
    while (dest[i] != NULL)
    {
        printf("In position %d of dest I have: %s\n", i, dest[i]);
        i++;
    }
}

int     main(int argc, char **argv)
{
    int     mode;
        
    if (argc < 2)
        return (0);
    
    if (!check_presence_of_wildcard(argv[1]))
        return (0);
    mode = scan_argument(argv[1]);
    if (mode == 1)
        sufix_mode(argv[1]);
    else if (mode == 0)
        prefix_mode(argv[1]);
    return (0);
}
