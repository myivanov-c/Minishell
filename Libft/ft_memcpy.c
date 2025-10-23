/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:48:29 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/21 23:32:32 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
   unsigned char *d;
   const unsigned char *s;

   d = (unsigned char *)dest;
   s = (const unsigned char *)src;
   if (dest == src || n == 0)
	return (dest);
   while (n > 0)
   {
        *d++ = *s++;
        n--;
   }
   return (dest);
}

int     main(void)
{
    char    dest[] = "Vou ter uma frase nova aq";
    char    src[] = "Aston Martin goes to dest";

    ft_memcpy(dest, src, 27);
    printf("%s\n", dest);
    return (0);
}
