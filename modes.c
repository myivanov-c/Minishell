/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:30:04 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/25 18:21:14 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     filter_mode_1(char *line_to_compare, char **res)
{
    int     result_first;
    int     result_second;
    
    if (!line_to_compare)
        return (0);
    result_first = filter_mode_1_helper(line_to_compare, res);
    result_second = filter_mode_helper(line_to_compare, res);
    if (result_first == 1 && result_second == 1)
        return (1);
    return (0);
}

int     filter_mode_2(char *line_to_compare, char **res)
{
    int     result_first;
    int     result_second;
    
    if (!line_to_compare)
        return (0);
    result_first = filter_mode_2_helper(line_to_compare, res);
    result_second = filter_mode_helper(line_to_compare, res);
    if (result_first == 1 && result_second == 1)
        return (1);
    return (0);
}

int     filter_mode_3(char *line_to_compare, char **res)
{
    int     result_first;
    int     result_second;
    int     result_third;

    if (!line_to_compare)
        return (0);
    result_first = filter_mode_1_helper(line_to_compare, res);
    result_second = filter_mode_2_helper(line_to_compare, res);
    result_third = filter_mode_helper(line_to_compare, res);
    if (result_first == 1 && result_second == 1 && result_third == 1)
        return (1);
    return (0);
}

int     filter_mode_4_and_5(char *line_to_compare, char **res)
{
    int     result;
    
    if (!line_to_compare)
        return (0);
    result = filter_mode_helper(line_to_compare, res);
    if (result == 1)
        return (1);
    return (0);
}

int     select_wildcard_mode(char *line_to_compare, char **res, int mode)
{   
    if (!line_to_compare)
        return (0);
    if (mode == 1)
        return (filter_mode_1(line_to_compare, res));
    else if (mode == 2)
        return (filter_mode_2(line_to_compare, res));
    else if (mode == 3)
        return (filter_mode_3(line_to_compare, res));
    else if (mode == 4 || mode == 5)
        return (filter_mode_4_and_5(line_to_compare, res));
    return (0);
}
