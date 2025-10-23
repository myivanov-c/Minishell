/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_memory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:07:49 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:41:13 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putnbr_hex_memory(unsigned long long n)
{
    char    *base;
    int     count;
    char    c;

    count = 0;
    base = "0123456789abcdef";
    if (n >= 16)
        count += ft_putnbr_hex_memory(n / 16);
    c = base[n % 16];
    count++;
    write(1, &c, 1);
    return (count);
}