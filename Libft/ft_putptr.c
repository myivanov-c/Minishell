/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:08:56 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:44:52 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putptr(void *ptr)
{
    int     count;
    
    if (!ptr)
        return (write(1, "(nil)", 5));
    count = 0;
    count += write(1, "0x", 2);
    count += ft_putnbr_hex_memory((unsigned long long)ptr);
    return (count);
}