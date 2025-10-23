/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 21:39:11 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/23 16:54:05 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     middle_loops(char *str, int i, int has_text, int has_star_before, int has_star_after)
{
    while (str[i] == '*')
    {
        has_star_before = 1;
        i++;
    }
    while (str[i] && str[i] != '*')
    {
        has_text = 1;
        i++;
    }
    while (str[i])
    {
        if (str[i] == '*')
            has_star_after = 1;
        i++;
    }
    if (has_star_before && has_text && has_star_after)
        return (1);
    return (0);
}

int scan_middle(char *str)
{
    int     i;
    int     has_text;
    int     has_star_before;
    int     has_star_after;
    int     res;

    i = 0;
    has_text = 0;
    has_star_before = 0;
    has_star_after = 0;
    res = middle_loops(str, i, has_text, has_star_before, has_star_after);
    if (res == 1)
        return (1);
    return (0);
   
}

int scan_prefix(char *str)
{
    int     i;
    int     has_text;

    i = 0;
    has_text = 0;
    if (str[0] == '*')
        return (0);
    while (str[i] && str[i] != '*')
    {
        has_text = 1;
        i++;
    }
    while (str[i])
    {
        if (str[i] == '*')
            return (has_text);
        i++;
    }
    return (0);
}

int scan_sufix(char *str)
{
    int     i;
    int     has_text;

    i = 0;
    has_text = 0;
    while (str[i] == '*')
        i++;
    if (str[i] != '\0')
        has_text = 1;
    if (str[0] == '*' && has_text)
        return (1);
    return (0);
}

int     scan_argument(char *str)
{
    int     mode;
    
    mode = -1;
    if (scan_middle(str) == 1)
    {
        mode = 2;
        return (mode);
    }
    else if (scan_prefix(str) == 1)
    {
        mode = 0;
        return (mode);
    }
    else if (scan_sufix(str) == 1)
    {
        mode = 1;
        return (mode);
    }
    return (mode);
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

void    middle_mode(char *str)
{
    int     size;
    char    *filter;
    int     start = 0;
    struct dirent *entry = NULL;
    char    **filtered_array;
    int     i;
    
    size = filter_data_size_mid(str, &start);
    filter = store_whats_in_wildcard_mid(str, start);
    filtered_array = total_filtered_outcomes_mid(entry, size, filter);
    i = 0;
    while (filtered_array[i] != NULL)
    {
        printf("Na posição %d tenho: %s\n", i + 1, filtered_array[i]);
        i++;
    }
}

int     main(int argc, char **argv)
{
    int     mode;
    int     is_present;
    
    if (argc < 2)
        return (0);
    is_present = check_presence_of_wildcard(argv[1]);
    if (is_present == 0)
        return (0);
    mode = scan_argument(argv[1]);
    if (mode == 2)
        middle_mode(argv[1]);
    else if (mode == 1)
        sufix_mode(argv[1]);
    else if (mode == 0)
        prefix_mode(argv[1]);
    return (0);
}
