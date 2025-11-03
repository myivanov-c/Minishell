/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:18:12 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/30 14:59:15 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *d;
    const unsigned char *s;

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    if (d == s || n == 0)
        return (dest);
    if (d < s)
    {
        while (n > 0)
        {
            *d++ = *s++;
            n--;
        }
    }
    else
    {
        while (n > 0)
        {
            n--;
            d[n] = s[n];
        }
    }
    return (dest);   
}
