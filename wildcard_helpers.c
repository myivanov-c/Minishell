/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:30:18 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/22 22:09:08 by mykytaivano      ###   ########.fr       */
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

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int     ft_strncmp(char *s1, char *s2, int n)
{
    int     i;

    i = 0;
    while (s1[i] && s2[i] && i < n)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (i < n)
        return (s1[i] - s2[i]);
    return (0);
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
