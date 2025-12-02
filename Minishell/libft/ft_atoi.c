/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:21:37 by causilva          #+#    #+#             */
/*   Updated: 2025/11/20 14:57:06 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	while (ft_isspace(*nptr))
		nptr++;
	result = 0;
	sign = 1 - 2 * (*nptr == '-');
	i = (*nptr == '-' || *nptr == '+');
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
/* 
#include <stdio.h>
#include <stdlib.h>
int	test_ft_atoi()
{
	if (ft_atoi("") !=  atoi(""))
		return (1);
	if (ft_atoi(" -42a") !=  atoi(" -42a"))
		return (2);
	if (ft_atoi("123 123") !=  atoi("123 123"))
		return (3);
	if (ft_atoi("--42") !=  atoi("--42"))
		return (4);
	return (0);
}
int	main(void)
{
	if (test_ft_atoi() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_atoi());
	printf("\n");
}
 */