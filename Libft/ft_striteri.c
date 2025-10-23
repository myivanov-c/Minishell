/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:04:33 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 15:45:51 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*static void    ft_lower(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
    {
        *c = *c - 32;
    }
}*/

void    ft_striteri(char *s, void (*f)(unsigned int,  char*))
{
    unsigned int    i;

    if (!s || !f)
    {
        return ;
    }
    i = 0;
    while (s[i] != '\0')
    {
        f(i, &s[i]);
        i++;
    }   
}

/*int     main(void)
{
    char    s[] = "ASTON MARTIN VANQUISH";
    
    ft_striteri(s, ft_lower);
    printf("%s\n", s);
    return (0);
}*/