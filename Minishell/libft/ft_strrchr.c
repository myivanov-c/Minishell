/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:58:55 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:13:00 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((unsigned char) c == '\0')
		return ((char *) &s[i]);
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>
int	test_ft_strrchr()
{
	if (ft_strrchr("babca", 'b') != strrchr("babca", 'b'))
		return (1);
	if (ft_strrchr("abca", '1') != strrchr("abca", '1'))
		return (2);
	if (ft_strrchr("abc", 'a' + 256) != strrchr("abc", 'a' + 256))
		return (3);
	if (ft_strrchr("abc", 0) != strrchr("abc", 0))
		return (4);
	if (ft_strrchr("", 'a') != strrchr("", 'a'))
		return (5);
	if (ft_strrchr("", 0) != strrchr("", 0))
		return (6);
	return (0);
}
int	main(void)
{
	if (test_ft_strrchr() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strrchr());
	printf("\n");
}
 */