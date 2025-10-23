/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:31:35 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/16 17:39:57 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar_fd(char c, int fd)
{
    write (fd, &c, 1);
}

/*int     main(void)
{
    char    c;

    c = 'A';
    ft_putchar_fd(c, 1);
    return (0);
}*/