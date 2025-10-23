/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:56:06 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/04/19 14:51:34 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putnbr_fd(int n, int fd)
{
    char    c;
    long    num;
    
    num = (long)n;
    if (num < 0)
    {
        write(fd, "-", 1);
        num = -num;
    }
    if (num >= 10)
    {
        ft_putnbr_fd(num / 10, fd);
    }
    c = (num % 10) + '0';
    write(fd, &c, 1);
}

/*int     main(void)
{
    int     n;

    n = 812;
    ft_putnbr_fd(n, 1);
    return (0);
}*/