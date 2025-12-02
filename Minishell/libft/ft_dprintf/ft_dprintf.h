/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:36:23 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 20:47:50 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

# define BASE_DEC "0123456789"
# define BASE_LHEX "0123456789abcdef"
# define BASE_UHEX "0123456789ABCDEF"

typedef struct s_iocount
{
	int	read;
	int	printed;
}	t_iocount;

//----------------------------------------------
//-----------------FT_DPRINTF.C------------------
//----------------------------------------------
int			ft_dprintf(int fd, const char *format, ...);
t_iocount	choose_print(int fd, char c, va_list *args);
t_iocount	print_pure(int fd, const char *s);

//----------------------------------------------
//-------------------DPRINTS.C-------------------
//----------------------------------------------
int			print_c(int fd, unsigned char c);
int			print_s(int fd, const char *s);	
int			print_p(int fd, void *ptr);
int			print_li(int fd, long n);
int			print_lubase(int fd, unsigned long n, const char *base);

#endif