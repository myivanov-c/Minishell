/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:13:23 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/30 14:59:58 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    while (n > 0)
    {
        *ptr = 0;
        ptr++;
        n--;
    }
}
