/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:30:18 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/23 17:26:02 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_array(char **arr, int k)
{
    int     i;

    i = 0;
    if (!arr)
        return ;
    while (i < k && arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

int     check_presence_of_wildcard(char *str)
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
