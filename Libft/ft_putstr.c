/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:59:50 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:45:34 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putstr(const char *s)
{
    int     i;

    i = 0;
    if (!s)
    {
        write(1, "(null)", 6);
        return (6);
    }   
    while (s[i] != '\0')
    {
        write(1, &s[i], 1);
        i++;
    }
    return (i);
}