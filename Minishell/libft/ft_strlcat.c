/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:38:16 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:57:54 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0')
	{
		if (i == size)
			return (i + ft_strlen(src));
		i++;
	}
	if (i == size)
		return (i + ft_strlen(src));
	return (i + ft_strlcpy(&dst[i], src, size - i));
}
/* 
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int	test_ft_strlcat()
{
	char	dst[20];
	char	dst2[20];

	dst[0] = '\0';
	dst2[0] = '\0';
	ft_strlcat(dst, "123", -1);
	strlcat(dst2, "123", -1);
	if (strcmp(dst, dst2) != 0)
		return (1);
	ft_strlcat(dst, "123", 0);
	strlcat(dst2, "123", 0);
	if (strcmp(dst, dst2) != 0)
		return (2);
	ft_strlcat(dst, "123", 2);
	strlcat(dst2, "123", 2);
	if (strcmp(dst, dst2) != 0)
		return (3);
	ft_strlcat(dst, "123", 1);
	strlcat(dst2, "123", 1);
	if (strcmp(dst, dst2) != 0)
		return (4);
	ft_strlcat(dst, "", 4);
	strlcat(dst2, "", 4);
	if (strcmp(dst, dst2) != 0)
		return (5);
	ft_strlcat(dst, "123", 9);
	strlcat(dst2, "123", 9);
	if (strcmp(dst, dst2) != 0)
		return (6);
	return (0);
}
int	main(void)
{
	if (test_ft_strlcat() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strlcat());
	printf("\n");
}
 */