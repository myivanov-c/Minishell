/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:31:44 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/10 22:00:15 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int     ft_isdigit(int c)
{
    if (c < 48 || c > 57)
    {
        return (0);
    }
    return (1);
}

/*int     main(void)
{
    int     c;

    c = '9';
    printf("%d\n", ft_isdigit(c));
    return (0);
}*/