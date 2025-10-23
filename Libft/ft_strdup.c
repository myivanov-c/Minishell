/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:50:12 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 15:19:59 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"


char    *ft_strdup(const char *s)
{
    char    *copy;
    size_t  i;

    copy = (char *)malloc(ft_strlen(s) + 1);
    if (!copy)
    {
        return (NULL);
    }
    i = 0;
    while (s[i] != '\0')
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

/*int main(void)
{
    char    *original = "Aston Martin Valhalla";
    char    *copy;

    copy = ft_strdup(original);
    if (!copy)
    {
        printf("Erro ao duplicar.\n");
        return (1);
    }
    printf("Original: %s\n", original);
    printf("Cópia:    %s\n", copy);
    free(copy);
    return (0);
}*/