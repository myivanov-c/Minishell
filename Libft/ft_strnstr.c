/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:12:28 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/12 17:05:20 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

char    *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
    size_t   i;
    size_t   j;
  
    i = 0;
    if (needle[0] == '\0')
    {
        return ((char *)haystack);
    }
    while (haystack[i] != '\0' && i < n)
    {
        if (haystack[i] == needle[0])
        {
            j = 0;
            while (needle[j] != '\0' && i + j < n && haystack[i + j] == needle[j])
            {
                j++;
            }
            if (needle[j] == '\0')
            {
                return ((char *)(haystack + i));
            }
        }
        i++;
    }
    return (NULL);
}

/*int     main(void)
{
    char    haystack[] = "Aston Martin";
    char    needle [] = "ar";

    char     *result = ft_strnstr(haystack, needle, 8);
    if (result)
    {
        printf("Encontrado: %s\n", result);
    }
    else
    {
        printf("Não encontrado.\n");
    }
    return (0);
}*/