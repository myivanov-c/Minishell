/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:40:01 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 15:46:00 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	t_iocount	total;
	t_iocount	func_return;

	if (!format)
		return (-1);
	va_start(args, format);
	total = (t_iocount){0, 0};
	func_return = (t_iocount){0, 1};
	while (format[total.read] != '\0' && func_return.printed >= 0)
	{
		if (format[total.read] == '%')
			func_return = choose_print(fd, format[++total.read], &args);
		else
			func_return = print_pure(fd, &format[total.read]);
		total.read += func_return.read;
		total.printed += func_return.printed;
	}
	if (func_return.printed < 0)
		return (func_return.printed);
	va_end(args);
	return (total.printed);
}

t_iocount	choose_print(int fd, char c, va_list *args)
{
	int	printed;

	if (c == 'c')
		printed = print_c(fd, (unsigned char) va_arg(*args, int));
	else if (c == 's')
		printed = print_s(fd, va_arg(*args, const char *));
	else if (c == 'p')
		printed = print_p(fd, va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		printed = print_li(fd, va_arg(*args, int));
	else if (c == 'u')
		printed = print_li(fd, va_arg(*args, unsigned int));
	else if (c == 'x')
		printed = print_lubase(fd, va_arg(*args, unsigned int), BASE_LHEX);
	else if (c == 'X')
		printed = print_lubase(fd, va_arg(*args, unsigned int), BASE_UHEX);
	else if (c == '%')
		printed = write(fd, "%", 1);
	else
		return ((t_iocount){0, -1});
	return ((t_iocount){1, printed});
}

t_iocount	print_pure(int fd, const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '%')
		i++;
	return ((t_iocount){i, write(fd, s, i)});
}
