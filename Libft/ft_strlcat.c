/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:44:54 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/26 15:25:36 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"

size_t      ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t i;
    size_t     dest_len;
    size_t     src_len;
    
    if (dest == NULL && size > 0)
        return (ft_strlen(src));
    dest_len = ft_strlen(dest);
    src_len = ft_strlen(src);
    i = 0;
    if (size <= dest_len)
    {
        return (size + src_len);
    }
    while (src[i] != '\0' && dest_len + i < size - 1)
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (dest_len + src_len);
}

/*int     main(void)
{
    char    src[] = "Martin";
    char    dest[20] = "Aston ";
    size_t  len;

    len = ft_strlcat(dest, src, 13);
    printf("%s\n", dest);
    printf("%zu\n", len);
    return (0);
}*/