/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:53:22 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/07/01 17:39:12 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int     ft_printf(const char *format, ...);
int     ft_putchar(char c);
int     ft_putstr(const char *str);
int     ft_putnbr(int n);
int     ft_putnbr_unsigned(unsigned int n);
int     ft_putnbr_hex_uppercase(unsigned int n);
int     ft_putnbr_hex_lowercase(unsigned int n);
int     ft_putnbr_hex_memory(unsigned long long n);
int     ft_putptr(void *ptr);
int     ft_handle_conversion(const char *format, int i, va_list *ap);

#endif 