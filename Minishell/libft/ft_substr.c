/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:50:17 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:16:05 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	size;
	size_t	i;

	s_len = ft_strlen(s);
	if (s_len <= start)
		size = 1;
	else if (s_len - start <= len)
		size = 1 + s_len - start;
	else
		size = 1 + len;
	substring = (char *) malloc(size * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		substring[i] = (char) s[i + start];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	test_ft_substr()
{
	char	string[] = "12345678";
	char	*sub;

	sub = ft_substr(string, 3, 3);
	if (strcmp(sub, "456") != 0)
		return (1);
	free(sub);
	return (0);
}
int	main(void)
{
	if (test_ft_substr() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_substr());
	printf("\n");
}
 */