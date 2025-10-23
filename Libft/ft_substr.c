/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:11:55 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/26 13:38:16 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "libft.h"

static char     *ft_empty_substr(void)
{
    char    *sub;

    sub = (char *)malloc(1);
    if (!sub)
    {
        return (NULL);
    }
    sub[0] = '\0';
    return (sub);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  i;
    size_t  s_len;
    
    if(!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
    {
        return (ft_empty_substr());
    }
    if (len > s_len - start)
        len = s_len - start;
    sub = (char *)malloc(len + 1);
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}

/*int     main(void) 
{
    char    *s = "Aston Martin Vanquish";
    char    *sub;

    sub = ft_substr(s, 13, 30);
    if (!sub)
    {
        printf("Falha ao alocar memória\n");
    }
    else
    {
        printf("%s\n", sub);
    }
    free (sub);
    return (0);
}*/
