/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:27:05 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:01:29 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = (char) src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/* 
#include <stdio.h>
#include <bsd/string.h>
int	test_ft_strlcpy()
{
	char	dst[20];

	if (ft_strlcpy(dst, "123", -1) != strlcpy(dst, "123", -1))
		return (1);
	if (ft_strlcpy(dst, "", 0) != strlcpy(dst, "", 0))
		return (2);
	if (ft_strlcpy(dst, "", 6) != strlcpy(dst, "", 6))
		return (3);
	if (ft_strlcpy(dst, "123", 0) != strlcpy(dst, "123", 0))
		return (4);
	if (ft_strlcpy(dst, "123", 2) != strlcpy(dst, "123", 2))
		return (5);
	if (ft_strlcpy(dst, "123", 3) != strlcpy(dst, "123", 3))
		return (6);
	if (ft_strlcpy(dst, "123", 4) != strlcpy(dst, "123", 4))
		return (7);
	if (ft_strlcpy(dst, "123", 5) != strlcpy(dst, "123", 5))
		return (8);
	return (0);
}
int	main(void)
{
	if (test_ft_strlcpy() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strlcpy());
	printf("\n");
}
 */