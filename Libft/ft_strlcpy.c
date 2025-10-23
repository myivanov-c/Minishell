/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:30:27 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 18:22:09 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"

size_t      ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t  i;

    i = 0;
    if (size == 0)
    {
        return (ft_strlen(src));
    }
    while (src[i] != '\0' && i < size - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}

/*int     main(void)
{
    char     src[] = "Aston Martin Valhala";
    char    dest[30];
    size_t  len;
    
    printf("Antes da função: %s\n", dest);
    len = ft_strlcpy(dest, src, 30);
    printf("Depois da função: %s\n", dest);
    printf("Src len: %zu\n", len);
    return (0);
}*/