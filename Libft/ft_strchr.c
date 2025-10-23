/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:40:59 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 18:41:29 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strchr(const char *s, int c)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
        {
            return ((char *)&s[i]);
        }
        i++;
    }
    if ((char)c == '\0')
    {
        return ((char *)&s[i]);
    }
    return (NULL);
}

/*int     main(void)
{
    char    s[] = "Ferrai SP3 Daytona";
    char    *result = ft_strchr(s, 'Q');
    
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