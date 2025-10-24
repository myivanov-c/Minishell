/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:30:04 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/24 17:30:42 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     filter_mode_1(char *line_to_compare, char **res, char *str)
{
    int     result_first;
    int     result_second;

    result_first = filter_mode_1_helper(line_to_compare, res, str);
    result_second = filter_mode_helper(line_to_compare, res, str);
    if (result_first == 1 && result_second == 1)
        return (1);
    return (0);
}

int     filter_mode_2(char *line_to_compare, char **res, char *str)
{
    int     result_first;
    int     result_second;
    
    result_first = filter_mode_2_helper(line_to_compare, res, str);
    result_second = filter_mode_helper(line_to_compare, res, str);
    if (result_first == 1 && result_second == 1)
        return (1);
    return (0);
}

int     filter_mode_3(char *line_to_compare, char **res, char *str)
{
    int     result_first;
    int     result_second;
    int     result_third;

    result_first = filter_mode_1_helper(line_to_compare, res, str);
    result_second = filter_mode_2_helper(line_to_compare, res, str);
    result_third = filter_mode_helper(line_to_compare, res, str);
    if (result_first == 1 && result_second == 1 && result_third == 1)
        return (1);
    return (0);
}

int     filter_mode_4_and_5(char *line_to_compare, char **res, char *str)
{
    int     result;

    if (line_to_compare[0] == '.')
        return (0);
    result = filter_mode_helper(line_to_compare, res, str);
    if (result == 1)
        return (1);
    return (0);
}

int     select_wildcard_mode(char *line_to_compare, char **res, char *str)
{
    int     mode;
    
    mode = filter_mode(str);
    if (mode == 1)
        return (filter_mode_1(line_to_compare, res, str));
    else if (mode == 2)
        return (filter_mode_2(line_to_compare, res, str));
    else if (mode == 3)
        return (filter_mode_3(line_to_compare, res, str));
    else if (mode == 4 || mode == 5)
        return (filter_mode_4_and_5(line_to_compare, res, str));
    return (0);
}
