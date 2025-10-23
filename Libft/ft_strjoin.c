/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:16:58 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/26 13:30:26 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static void     ft_strjoin_copy(char *dest, const char *s1, const char *s2)
{
    size_t  i;
    size_t  j;
    
    i = 0;
    while (s1[i] != '\0')
    {
        dest[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        dest[i] = s2[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}


char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *new_string;
    size_t  len_s1;
    size_t  len_s2;
    
    if (!s1 || !s2)
        return (NULL);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    new_string = (char *)malloc(len_s1 + len_s2 + 1);
    if (!new_string)
    {
        return (NULL);
    }
    ft_strjoin_copy(new_string, s1, s2);
    return (new_string);
}

/*int     main(void)
{
    char    *s1 = "Aston ";
    char    *s2 = "Martin Valhala";
    char    *new_string;

    new_string = ft_strjoin(s1, s2);
    if (!new_string)
    {
        printf("Falha ao alocar memória.\n");
    }
    else
    {
        printf("%s\n", new_string);
    }
    free (new_string);
    return (0);
}*/