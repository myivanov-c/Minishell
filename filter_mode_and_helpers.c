/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_mode_and_helpers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:27:19 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/24 17:29:40 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    filter_mode_loops(char  *str, int *has_start, int *has_end, int *has_word)
{
    int     i;

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
    int     mode;
    
    mode = -1;
    has_start = 0;
    has_end = 0;
    has_word = 0;
    filter_mode_loops(str, &has_start, &has_end, &has_word);
    if (has_start && has_word && !has_end) // *abc*das
        mode = 1;
    else if (!has_start && has_word && has_end) // abc*asd*
        mode = 2;
    else if (!has_start && has_word && !has_end) // abs*ads
        mode = 3;
    else if (has_start && has_word && has_end) // *ada*das*
        mode = 4;
    else if (has_start && !has_word) // ***
        mode = 5;
    return (mode);
}

int     filter_mode_1_helper(char *line_to_compare, char **res, char *str)
{
    int     i;
    int     count;;
    int     res_count;
    int     size;
    
    res = filtered_array_multi(str);
    if (!res)
        return (0);
    res_count = 0;
    count = 0;
    while (res[res_count + 1] != NULL)
        res_count++;
    i = ft_strlen(line_to_compare);
    size = ft_strlen(res[res_count]);
    while (count < size)
    {
        i--;
        count++;
    }
    if (ft_strncmp(&line_to_compare[i], res[res_count], size) == 0)
        return (1);
    return (0);
}

int     filter_mode_helper(char *line_to_compare, char **res, char *str)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    res = filtered_array_multi(str);
    if (!res)
    {
        free(res);
        return (0);
    }
    while (line_to_compare[i] != '\0')
    {
        if (res[j] != NULL && ft_strncmp(&line_to_compare[i], res[j], ft_strlen(res[j])) == 0)
        {
            i = i + ft_strlen(res[j]) - 1;
            j++;
        }
        else
            i++;
    }
    if (res[j] == NULL)
        return (1);
    return (0);
}

int     filter_mode_2_helper(char *line_to_compare, char **res, char *str)
{
    int     i;
    int     res_size;

    res = ft_split(str, '*');
    if (line_to_compare[0] == '.')
        return (0);
    res_size = ft_strlen(res[0]);
    i = 0;
    if (ft_strncmp(&line_to_compare[i], res[0], res_size) != 0)
        return (0);
    return (1);
}
