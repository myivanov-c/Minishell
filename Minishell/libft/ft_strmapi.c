/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:36:59 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:08:10 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		i;
	char	*string;

	size = ft_strlen(s) + 1;
	string = (char *) malloc(size);
	if (!string)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		if (f)
			string[i] = f(i, s[i]);
		else
			string[i] = '\0';
		i++;
	}
	string[i] = '\0';
	return (string);
}
/* 
#include <stdio.h>
#include <string.h>
char	f(unsigned int i, char c)
{
	return (i + c);
}
int	test_ft_strmapi()
{
	char	*mapi;

	mapi = ft_strmapi("01234", &f);
	if (strcmp(mapi, "02468") != 0)
		return (1);
	free(mapi);
	return (0);
}
int	main(void)
{
	if (test_ft_strmapi() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strmapi());
	printf("\n");
}
 */