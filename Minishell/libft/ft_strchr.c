/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:58:52 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:54:51 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) &s[i]);
	return (0);
}
/* 
#include <stdio.h>
#include <string.h>
int	test_ft_strchr()
{
	if (ft_strchr("abc", 'a') != strchr("abc", 'a'))
		return (1);
	if (ft_strchr("abc", '1') != strchr("abc", '1'))
		return (2);
	if (ft_strchr("abc", 'a' + 256) != strchr("abc", 'a' + 256))
		return (3);
	if (ft_strchr("abc", 0) != strchr("abc", 0))
		return (4);
	if (ft_strchr("", 'a') != strchr("", 'a'))
		return (5);
	if (ft_strchr("", 0) != strchr("", 0))
		return (6);
	return (0);
}
int	main(void)
{
	if (test_ft_strchr() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strchr());
	printf("\n");
}
 */