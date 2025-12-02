/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:15:09 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:56:37 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*string;

	size = ft_strlen(s) + 1;
	string = (char *) malloc(size);
	if (!string)
		return (NULL);
	ft_strlcpy(string, s, size);
	return (string);
}
/* 
#include <stdio.h>
#include <string.h>
# include <stdlib.h>
int	test_ft_strdup()
{
	char	*string1;

	string1 = ft_strdup("abc123");
	if (strcmp(string1, "abc123") != 0)
	{
		free(string1);
		return (1);
	}
	free(string1);
	string1 = ft_strdup("");
	if (strcmp(string1, "") != 0)
	{
		free(string1);
		return (2);
	}
	free(string1);
	return (0);
}
int	main(void)
{
	if (test_ft_strdup() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strdup());
	printf("\n");
}
 */