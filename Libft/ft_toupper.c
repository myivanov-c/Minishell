/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:22:59 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/11 16:34:12 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_toupper(int c)
{
    if (c >= 97 && c <= 122)
    {
        return (c - 32);
    }
    return (c);
}

/*int     main(void)
{
    int     c;
    
    c = 'a';
    printf("%c\n", ft_toupper(c));
    return (0);
}*/