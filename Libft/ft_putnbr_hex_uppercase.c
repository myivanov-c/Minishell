/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_uppercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:05:59 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:42:22 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putnbr_hex_uppercase(unsigned int n)
{
    char    *base;
    int     count;
    char    c;
    
    count = 0;
    base = "0123456789ABCDEF";
    if (n >= 16)
        count += ft_putnbr_hex_uppercase(n / 16);
    c = base[n % 16];
    count++;
    write(1, &c, 1);
    return (count);
}