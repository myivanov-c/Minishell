/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:09:41 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:39:53 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
/* 
#include <stdio.h>
#include <string.h>
int	test_ft_memcpy()
{
	char	array1[10] = "12345";
	char	array2[10];

	ft_memcpy(array2, array1, 10);
	if (strcmp(array1, array2) != 0)
		return (1);
	return (0);
}
int	main(void)
{
	if (test_ft_memcpy() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_memcpy());
	printf("\n");
}
 */