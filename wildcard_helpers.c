/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:30:18 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/25 16:02:54 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_array_split(char **arr)
{
    int     i;

    i = 0;
    if (!arr)
        return ;
    while (arr[i])
    {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    free(arr);
}

void    free_array_n(char **arr, int n)
{
    int     i;

    if (!arr || n <= 0)
        return ;
    i = 0;
    while (i < n)
    {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    free(arr);
}

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    if (s1 == s2)
        return (0);
    if (!s1)
        return (-1);
    if (!s2)
        return (1);
    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

void    sort_array(char **arr)
{
    int     i;
    int     swapped;
    char    *temp;

    if (!arr || !arr[0])
        return ;
    swapped = 1;
    while (swapped)
    {
        i = 0;
        swapped = 0;
        while (arr[i] && arr[i + 1])
        {
            if (ft_strcmp(arr[i], arr[i + 1]) > 0)
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
            i++;
        }
    }
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
