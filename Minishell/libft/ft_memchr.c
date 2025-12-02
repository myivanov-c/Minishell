/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:40:29 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:39:19 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char) c)
			return ((void *) &s[i]);
		i++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>
int	test_ft_memchr()
{
	char	array1[10] = "12345";

	if (ft_memchr(array1, '3', 10) != memchr(array1, '3', 10))
		return (1);
	if (ft_memchr(array1, '\0', 10) != memchr(array1, '\0', 10))
		return (2);
	if (ft_memchr(array1, '5', 3) != memchr(array1, '5', 3))
		return (3);
	if (ft_memchr(array1, 'a', 10) != memchr(array1, 'a', 10))
		return (4);
	return (0);
}
int	main(void)
{
	if (test_ft_memchr() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_memchr());
	printf("\n");
}
 */