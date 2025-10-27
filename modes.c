/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:30:04 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/27 12:50:30 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     filter_mode_1(char *line_to_compare, t_wildcard *w)
{
    int     result_first;
    int     result_second;
    
    if (!line_to_compare)
        return (0);
    result_first = filter_mode_1_helper(line_to_compare, w);
    result_second = filter_mode_helper(line_to_compare, w);
    if (result_first == 1 && result_second == 1)
        return (1);
    return (0);
}

int     filter_mode_2(char *line_to_compare, t_wildcard *w)
{
    int     result_first;
    int     result_second;
    
    if (!line_to_compare)
        return (0);
    result_first = filter_mode_2_helper(line_to_compare, w);
    result_second = filter_mode_helper(line_to_compare, w);
    if (result_first == 1 && result_second == 1)
        return (1);
    return (0);
}

int     filter_mode_3(char *line_to_compare, t_wildcard *w)
{
    int     result_first;
    int     result_second;
    int     result_third;

    if (!line_to_compare)
        return (0);
    result_first = filter_mode_1_helper(line_to_compare, w);
    result_second = filter_mode_2_helper(line_to_compare, w);
    result_third = filter_mode_helper(line_to_compare, w);
    if (result_first == 1 && result_second == 1 && result_third == 1)
        return (1);
    return (0);
}

int     filter_mode_4_and_5(char *line_to_compare, t_wildcard *w)
{
    int     result;
    
    if (!line_to_compare)
        return (0);
    result = filter_mode_helper(line_to_compare, w);
    if (result == 1)
        return (1);
    return (0);
}

int     select_wildcard_mode(char *line_to_compare, t_wildcard *w)
{   
    if (!line_to_compare)
        return (0);
    if (w->mode == 1)
        return (filter_mode_1(line_to_compare, w));
    else if (w->mode == 2)
        return (filter_mode_2(line_to_compare, w));
    else if (w->mode == 3)
        return (filter_mode_3(line_to_compare, w));
    else if (w->mode == 4 || w->mode == 5)
        return (filter_mode_4_and_5(line_to_compare, w));
    return (0);
}
