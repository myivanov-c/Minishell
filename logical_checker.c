/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_checker.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:26:37 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/28 17:54:58 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
# include "./Libft/libft.h"

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

int     has_operator(char **str, int i)
{
    int     j;
  
    if (!str[i])
        return (0);
    j = 0;
    while (str[i][j] != '\0')
    {
        if (str[i][j] == '&' || str[i][j] == '|')
            return (1);
        j++;
    }
    return (0);
}

int     check_for_logical_operators(char **res)
{
    int     i;
    int     valid;

    i = 0;
    valid = 0;
    while (res[i] != NULL)
    {
        if (has_operator(res, i))
        {
            if (ft_strcmp(res[i], "&&") == 0 || ft_strcmp(res[i], "||") == 0)
                valid++;
            else
                return (0);
        }
        i++;
    }
    return (valid);
}

int check_if_logical_mode(char *str)
{
    char **res;
    int i;
    int status;

    res = ft_split(str, ' ');
    if (!res)
        return (0);
    if (check_for_logical_operators(res) == 0)
        return (0);
    i = 0;
    status = 0;
    while (res[i] != NULL)
    {
        if ((ft_strcmp(res[i], "&&") == 0 || ft_strcmp(res[i], "||") == 0))
        {
            if (res[i + 1] && (ft_strcmp(res[i + 1], "&&") == 0 || ft_strcmp(res[i + 1], "||") == 0))
                break ;
            else
                status = 1;
        }
        i++;
    }
    if (status == 0)
        return (free_array_split(res), status);
    return (status);
}


int     main(int argc, char **argv)
{
    int     status;
    
    if (argc < 2)
        return (0);
    status = check_if_logical_mode(argv[1]);
    printf("Status check: %d\n", status);
    return (0);
}