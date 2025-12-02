/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:25:18 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 13:37:16 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > ((size_t)-1) / (2 * size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/* 
#include <stdio.h>
#include <string.h>
# include <stdlib.h>
int	test_ft_calloc()
{
	char	*string1;
	int		i;

	string1 = ft_calloc(10000, sizeof(char));
	i = 0;
	while (i < 10000)
	{
		if (string1[i] != 0)
		{
			free(string1);
			return (1);
		}
		i++;
	}
	free(string1);
	return (0);
}
int	main(void)
{
	if (test_ft_calloc() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_calloc());
	printf("\n");
}
 */