/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:42:06 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 15:44:06 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
    {
        return ;
    }
    new -> next = *lst;
    *lst = new;
}

/*int     main(void)
{
    t_list  *pista = NULL;
    t_list  *carro1;
    t_list  *carro2;

    carro1 = ft_lstnew("Audi");
    carro2 = ft_lstnew("BMW");
    
    ft_lstadd_front(&pista, carro1);
    ft_lstadd_front(&pista, carro2);
    printf("Primeiro carro: %s\n", (char *)pista -> content);
    printf("Segundo carro: %s\n", (char *)pista -> next -> content);
    free(carro1);
    free(carro2);
    return (0);
}*/