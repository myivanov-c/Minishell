/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:03:55 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:43:03 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putnbr_unsigned(unsigned int n)
{
    unsigned int    count;
    char            c;
    
    count = 0;
    if (n >= 10)
        count += ft_putnbr_unsigned(n / 10);
    c = (n % 10) + '0';
    count++;
    write(1, &c, 1);
    return (count);
}