/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:03:15 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:43:51 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putnbr(int n)
{
    char    c;
    int     count;
    long    num;

    count = 0;
    num = (long)n;
    if (num < 0)
    {
        write(1, "-", 1);
        count++;
        num = -num;
    }
    if (num >= 10)
        count += ft_putnbr(num / 10);
    c = (num % 10) + '0';
    count++;
    write(1, &c, 1);
    return (count);
}