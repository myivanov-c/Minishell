/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:40:30 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:52:55 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}
/* 
int	main(void)
{
	ft_putnbr_fd(0, 1);
	ft_putendl_fd("", 1);
	ft_putnbr_fd(42, 1);
	ft_putendl_fd("", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putendl_fd("", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putendl_fd("", 1);
}
 */