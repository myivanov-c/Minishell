/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_mode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:27:19 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/27 13:04:12 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    filter_mode_loops(char  *str, int *has_start, int *has_end, int *has_word)
{
    int     i;

    if (!str)
        return ;
    i = 0;
    while (str[i] == '*')
    {
        *has_start = 1;
        i++;
    }
    while (str[i] && str[i] != '*')
    {
        *has_word = 1;
        i++;
    }
    while (str[i])
    {
        if (str[i] == '*' && str[i + 1] == '\0')
            *has_end = 1;
        i++;
    }
}

int     filter_mode(char *str)
{
    int     has_start;
    int     has_end;
    int     has_word;
    
    if (!str || !str[0])
        return (-1);
    has_start = 0;
    has_end = 0;
    has_word = 0;
    filter_mode_loops(str, &has_start, &has_end, &has_word);
    if (has_start && has_word && !has_end) // *abc*das
        return (1);
    else if (!has_start && has_word && has_end) // abc*asd*
        return (2);
    else if (!has_start && has_word && !has_end) // abs*ads
        return (3);
    else if (has_start && has_word && has_end) // *ada*das*
        return (4);
    else if (has_start && !has_word) // ***
        return (5);
    return (-1);
}

int     filter_mode_1_helper(char *line_to_compare, t_wildcard *w)
{
    int     i;
    size_t     len;
    int     res_count;
    size_t     size;
    
    if (!line_to_compare)
        return (0);
    if (line_to_compare[0] == '.' && !pattern_allows_hidden(w))
	    return (0);
    res_count = 0;
    while (w->split_chars[res_count + 1] != NULL)
        res_count++;
    size = ft_strlen(w->split_chars[res_count]);
    len = ft_strlen(line_to_compare);
    if (size > len)
        return(0);
    i = len - size;
    if (ft_strncmp(line_to_compare + i, w->split_chars[res_count], size) == 0)
        return (1);
    return (0);
}

int     filter_mode_helper(char *line_to_compare, t_wildcard *w)
{
    int i;
    int j;

    if (!line_to_compare)
        return (0);
    i = 0;
    j = 0;
    if (line_to_compare[0] == '.' && !pattern_allows_hidden(w))
	    return (0);
    if (all_strings_empty(w))
        return (1);
    while (line_to_compare[i] && w->split_chars[j])
    {
        if (ft_strncmp(line_to_compare + i, w->split_chars[j], ft_strlen(w->split_chars[j])) == 0)
        {
            i = i + ft_strlen(w->split_chars[j]);
            j++;
        }
        else
            i++;
    }
    if (w->split_chars[j] == NULL)
        return (1);
    return (0);
}

int     filter_mode_2_helper(char *line_to_compare, t_wildcard *w)
{
    size_t     len;
    
    if (!line_to_compare)
        return (0);
    if (line_to_compare[0] == '.' && !pattern_allows_hidden(w))
	    return (0);
    len = ft_strlen(w->split_chars[0]);
    if (len > ft_strlen(line_to_compare))
        return (0);
    if (ft_strncmp(line_to_compare, w->split_chars[0], len) == 0)
        return (1);
    return (0);
}

