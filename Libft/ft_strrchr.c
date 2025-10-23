/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:23:16 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 18:47:33 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    int  i;

    i = ft_strlen(s);
    while (i >= 0)
    {
        if (s[i] == (char)c)
        {
            return ((char *)&s[i]);
        }
        i--;
    }
    return (NULL);
}

/*int     main(void)
{
    char    s[] = "Bugatti Chiron Super Sport";
    char    *result = ft_strrchr(s, 'B');

    if (result)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("Caracter não encontrado.\n");
    }
    return (0);
}*/