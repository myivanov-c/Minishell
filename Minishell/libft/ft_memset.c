/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:35:37 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:44:15 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) s)[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
/* 
#include <stdio.h>
int	test_ft_memset()
{
	char	array[100];
	int		i;

	ft_memset(&array, 'a', 100);
	i = 0;
	while (i < 100)
	{
		if (array[i] != 'a')
			return (1);
		i++;
	}
	return (0);
}
int	main(void)
{
	if (test_ft_memset() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_memset());
	printf("\n");
}
 */