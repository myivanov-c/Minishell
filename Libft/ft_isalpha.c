/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:31:25 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/10 21:29:56 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int    ft_isalpha(int c)
{
    if (c < 65 || (c > 90 && c < 97) || c > 122)
    {
        return (0);
    }
    return (1);
}

/*int     main(void)
{
    int c;
    
    c = '+';
    printf("%d\n", ft_isalpha(c));
    return (0);
}*/