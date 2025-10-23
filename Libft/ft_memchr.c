/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:29:34 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/13 10:22:17 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i = 0;
    unsigned char *ptr = (unsigned char *)s;

    while (i < n)
    {
        if (ptr[i] == (unsigned char)c)
        {
            return ((void *)&ptr[i]);
        }
        i++;
    }
    return (NULL);
}

/*int main(void)
{
    char s[] = "Aston Martin";
    char *result;

    result = ft_memchr(s, 'M', 10);
    if (result)
    {
        printf("Encontrado: %s\n", result);
    }
    else
    {
        printf("Caractere não encontrado.\n");
    }
    return 0;
}*/
