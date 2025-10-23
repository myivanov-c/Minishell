/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:15:57 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:37:04 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_handle_conversion(const char *format, int i, va_list *ap)
{
    int count;

    if(!format)
        return (0);
    count = 0;
    if (format[i] == 's')
        count += ft_putstr(va_arg(*ap, const char *));
    else if (format[i] == 'd' || format[i] == 'i')
        count += ft_putnbr(va_arg(*ap, int));
    else if (format[i] == 'u')
        count += ft_putnbr_unsigned(va_arg(*ap, unsigned int));
    else if (format[i] == 'c')
        count += ft_putchar(va_arg(*ap, int));
    else if (format[i] == '%')
        count += ft_putchar('%');
    else if (format[i] == 'x')
        count += ft_putnbr_hex_lowercase(va_arg(*ap, unsigned int));
    else if (format[i] == 'X')
        count += ft_putnbr_hex_uppercase(va_arg(*ap, unsigned int));
    else if (format[i] == 'p')
        count += ft_putptr(va_arg(*ap, void *));
    else
        count += ft_putchar('%');
    return (count);
}