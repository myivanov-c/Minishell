/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:31:01 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:10:12 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (((unsigned char *) s1)[i] != ((unsigned char *) s2)[i])
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
		i++;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>
int	test_ft_strncmp()
{
	if (ft_strncmp("abc", "abc", 5) != 0)
		return (1);
	if (ft_strncmp("abc1", "abc7", 5) >= 0)
		return (2);
	if (ft_strncmp("abc1", "abc7", 2) != 0)
		return (3);
	if (ft_strncmp("abc1", "", 2) <= 0)
		return (4);
	if (ft_strncmp("abc1", "", 0) != 0)
		return (5);
	if (ft_strncmp("", "", 0) != 0)
		return (6);
	return (0);
}
int	main(void)
{
	if (test_ft_strncmp() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strncmp());
	printf("\n");
}
 */