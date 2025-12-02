/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:35:25 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:43:59 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest <= src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		}
	}
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>
int	test_ft_memmove()
{
	char	array1[10] = "12345";
	char	*ptr = &array1[2];

	ft_memmove(ptr, array1, 10);
	if (strcmp(array1, "1212345") != 0)
		return (1);
	ft_memmove(array1, ptr, 10);
	if (strcmp(array1, "12345") != 0)
		return (2);
	return (0);
}
int	main(void)
{
	if (test_ft_memmove() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_memmove());
	printf("\n");
}
 */