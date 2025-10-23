/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:39:30 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/10 22:36:09 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

int     ft_isalnum(int c)
{
    if (ft_isdigit(c) || ft_isalpha(c))
    {
        return (1);
    }
    return (0);
}

/*int     main(void)
{
    int     c;

    c = 'A';
    printf("%d\n", ft_isalnum(c));
    return (0);
}*/