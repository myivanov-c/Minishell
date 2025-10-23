/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:32:54 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/16 20:45:53 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    if (!lst)
    {
        return (NULL);
    }
    while (lst -> next != NULL)
    {
        lst = lst -> next;
    }
    return (lst);
}

/*int     main(void)
{
    t_list *pista = NULL;
    t_list *carro1;
    t_list *carro2;
    t_list *carro3;
    t_list *ultimo;

    carro1 = ft_lstnew("Aston Martin Valkyrie");
    carro2 = ft_lstnew("Daytona SP3");
    carro3 = ft_lstnew("Tourbellion");
    
    ft_lstadd_front(&pista, carro1);
    ft_lstadd_front(&pista, carro2);
    ft_lstadd_front(&pista, carro3);
    
    ultimo = ft_lstlast(pista);
    printf("Ultimo carro: %s\n", (char *)ultimo -> content);
    free (carro1);
    free (carro2);
    free (carro3);
    return (0);
}*/