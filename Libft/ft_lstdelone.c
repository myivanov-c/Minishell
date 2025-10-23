/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:08:28 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/16 23:37:31 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*void    ft_del_content(void *content)
{
    free (content);
}*/

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
    {
        return ;
    }
    del(lst -> content);
    free (lst);
}

/*int     main (void)
{
    t_list  *carro;

    char    *marca = ft_strdup("Audi");
    if (!marca)
    {
        printf("Falha ao alocar memória.\n");
        return (1);
    }
    carro = ft_lstnew(marca);
    if (!carro)
	{
		printf("Falha ao alocar memória para node.\n");
		free(marca);
		return (1);
	}
    printf("Carro antes de apagar: %s\n", (char *)carro->content);

	ft_lstdelone(carro, ft_del_content);

	printf("Carro apagado.\n");

	return (0);
}*/