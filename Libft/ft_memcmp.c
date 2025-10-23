/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:55:24 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 18:53:16 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char     *pt1;
    const unsigned char     *pt2;
    size_t i;

    pt1 = (const unsigned char *)s1;
    pt2 = (const unsigned char *)s2;
    i = 0;
    while (i < n)
    {
        if (pt1[i] != pt2[i])
        {
            return (pt1[i] - pt2[i]);
        }
        i++;
    }
    return (0);
}

/*int     main(void)
{
    char    s1[] = "Aston";
    char    s2[] = "Aston Martin";
 
    int     result;
    
    result = ft_memcmp(s1, s2, 10);
    printf("%d\n", result);
    return (0);
}*/