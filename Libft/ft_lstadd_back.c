/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 22:35:44 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/04 14:54:57 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int    ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!lst ||  !new)
        return (-1);
    if (!(*lst))
    {
        *lst = new;
        return (0);
    }
    ft_lstlast(*lst)->next = new;
    return (0);
}

/*int     main(void)
{
    t_list  *pista = NULL;
    t_list  *carro1;
    t_list  *carro2;
    t_list  *carro3;

    carro1 = ft_lstnew("Hypercar");
    carro2 = ft_lstnew("Supercar");
    carro3 = ft_lstnew("Sportcar");

    ft_lstadd_back(&pista, carro1);
    ft_lstadd_back(&pista, carro2);
    ft_lstadd_back(&pista, carro3);

    printf("Primeiro carro: %s\n", (char *)pista -> content);
    printf("Segundo carro: %s\n", (char *)pista -> next -> content);
    printf("Terceiro carro: %s\n", (char *)pista -> next -> next -> content);
    
    free(carro1);
    free(carro2);
    free(carro3);
    return (0);
}*/