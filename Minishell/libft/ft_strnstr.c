/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:46:41 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:12:19 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	little_len = ft_strlen(little);
	i = 0;
	if (little_len == 0)
		return ((char *) &big[i]);
	while (big[i] != '\0' && i + little_len <= len)
	{
		if (ft_strncmp(&big[i], little, little_len) == 0)
			return ((char *) &big[i]);
		i++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <bsd/string.h>
int	test_ft_strnstr()
{
	if (ft_strnstr("abc123", "c1", 5) != strnstr("abc123", "c1", 5))
		return (1);
	if (ft_strnstr("abc123", "c1", 3) != strnstr("abc123", "c1", 3))
		return (2);
	if (ft_strnstr("abc123", "", 3) != strnstr("abc123", "", 3))
		return (3);
	if (ft_strnstr("", "c1", 3) != strnstr("", "c1", 3))
		return (4);
	if (ft_strnstr("abc123", "c1", 0) != strnstr("abc123", "c1", 0))
		return (5);
	return (0);
}
int	main(void)
{
	if (test_ft_strnstr() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strnstr());
	printf("\n");
}
 */