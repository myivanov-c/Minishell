/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:33:55 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/21 14:44:27 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void    *ft_memset(void *s, int c, size_t n)
{
    size_t  i;
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        ptr[i] = (const char)c;
        i++;
    }
    return (s);
}

/*int     main(void)
{
    char    str[] = "812 Competezione";
    int     c;
    size_t  n;
    
    c = '1';
    n = 3;
    ft_memset(str, c, n);
    printf("%s\n", str);
    return (0);
}*/