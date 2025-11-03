/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:48:29 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/30 14:59:30 by mykytaivano      ###   ########.fr       */
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

