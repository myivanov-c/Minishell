/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:35:48 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 15:26:54 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	print_c(int fd, unsigned char c)
{
	return (write(fd, &c, 1));
}

int	print_s(int fd, const char *s)
{
	if (!s)
		return (write(fd, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

int	print_p(int fd, void *ptr)
{
	int	write_return[2];

	if (!ptr)
		return (write(fd, "(nil)", 5));
	write_return[0] = write(fd, "0x", 2);
	if (write_return[0] < 0)
		return (write_return[0]);
	write_return[1] = print_lubase(fd, (unsigned long ) ptr, BASE_LHEX);
	if (write_return[1] < 0)
		return (write_return[1]);
	return (write_return[0] + write_return[1]);
}

int	print_li(int fd, long n)
{
	int	write_return[2];

	if (n < 0)
	{
		write_return[0] = write(fd, "-", 1);
		if (write_return[0] < 0)
			return (write_return[0]);
		write_return[1] = print_lubase(fd, -n, BASE_DEC);
	}
	else
	{
		write_return[0] = 0;
		write_return[1] = print_lubase(fd, n, BASE_DEC);
	}
	if (write_return[1] < 0)
		return (write_return[1]);
	return (write_return[0] + write_return[1]);
}

int	print_lubase(int fd, unsigned long n, const char *base)
{
	int	base_len;
	int	write_return[2];

	base_len = ft_strlen(base);
	if (n < (unsigned long) base_len)
		return (write(fd, &base[n], 1));
	write_return[0] = print_lubase(fd, n / base_len, base);
	if (write_return[0] < 0)
		return (write_return[0]);
	write_return[1] = print_lubase(fd, n % base_len, base);
	if (write_return[1] < 0)
		return (write_return[1]);
	return (write_return[0] + write_return[1]);
}
