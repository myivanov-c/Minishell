/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:13:23 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 17:35:28 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    while (n > 0)
    {
        *ptr = 0;
        ptr++;
        n--;
    }
}

int     main(void)
{
    char    str[] = "Tudo vai ficar com zeros";
    int     i;

    i = 0;
    ft_bzero(str, 24);
    while (i < 24)
    {
        printf("%d", str[i]);
        i++;
    }
    printf("\n");
    return (0);

    /*ft_bzero(str, 24);
    printf("%s\n", str);
    return (0);*/
}