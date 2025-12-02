/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:58:53 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 13:34:06 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) s)[i] = '\0';
		i++;
	}
}
/* 
#include <stdio.h>
int	test_ft_bzero()
{
	int	array[10000];
	int	i;

	ft_bzero(&array, 10000 * sizeof(int));
	i = 0;
	while (i < 10000)
	{
		if (array[i] != 0)
			return (1);
		i++;
	}
	return (0);
}
int	main(void)
{
	if (test_ft_bzero() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_bzero());
	printf("\n");
}
 */