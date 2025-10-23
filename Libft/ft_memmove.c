/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:18:12 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 18:12:31 by mykytaivano      ###   ########.fr       */
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

int     main(void)
{

    char    str[] = "ABCDEFGHIJK";

    printf("Antes da função: %s\n", str);
    ft_memmove(str + 2, str, 5);
    printf("Depois da função: %s\n", str);
    return (0);

    
    /*char    str[] = "911 Turbo S";
    char    dest[20] = "";

    printf("Antes da função: %s\n", dest);
    ft_memmove(dest, str, 11);
    printf("Depois da função: %s\n", dest);
    return (0);*/
}