/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:59:45 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/10/23 17:26:48 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_strncmp(const char *s1, const char *s2, int n)
{
    int  i;

    i = 0;
    while (i < n && s1[i] != '\0' && s2[i] != '\0')
    {
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
        {
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);    
        }
        i++;
    }
    if (i < n)
    {
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
    }
    return (0);   
}

/*int     main(void)
{
    char    s1[] = "Bston";
    char    s2[] = "Aston";
    int     result;

    result = ft_strncmp(s1, s2, 7);
    printf("%d\n", result);
    return (0);
}*/