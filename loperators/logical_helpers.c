/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:23:36 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/07 18:54:58 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loperators.h"


int     is_operator(char *s)
{
    return (ft_strcmp(s, "&&") == 0 || ft_strcmp(s, "||") == 0);
}

int     is_paren(char *s)
{
    return (ft_strcmp(s, "(") == 0 || ft_strcmp(s, ")") == 0);
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