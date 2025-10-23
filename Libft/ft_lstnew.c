/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:06:21 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/16 19:37:15 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
    {
        return (NULL);
    }
    node -> content = content;
    node -> next = NULL;
    return (node);
}

/*int     main(void)
{
    char    *car = "CC850";
    t_list  *node;

    node = ft_lstnew(car);
    if (!node)
    {
        printf("Falha ao alocar memória.\n");
    }
    else
    {
        printf("Content: %s\n", (char *)node -> content);
        if (node -> next == NULL)
        {
            printf("Next: NULL\n");
        }
    }
    free (node);
    return (0);
}*/