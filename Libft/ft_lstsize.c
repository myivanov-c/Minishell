/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:18:31 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/16 20:31:44 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int     ft_lstsize(t_list *lst)
{
    int     count;
    
    count = 0;
    while (lst != NULL)
    {
        count++;
        lst = lst -> next;
    }
    return (count);
}

/*int     main(void)
{
    t_list *pista = NULL;
    t_list *carro1;
    t_list *carro2;
    t_list *carro3;

    carro1 = ft_lstnew("Aston Martin Valkyrie");
    carro2 = ft_lstnew("Daytona SP3");
    carro3 = ft_lstnew("Tourbellion");
    
    ft_lstadd_front(&pista, carro1);
    ft_lstadd_front(&pista, carro2);
    ft_lstadd_front(&pista, carro3);
    
    
    printf("Numero de carros na pista: %d\n", ft_lstsize(pista));
    free (carro1);
    free (carro2);
    free (carro3);
    return (0);
}*/