/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:52:02 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:19:37 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	string = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, len1 + 1);
	ft_strlcat(string, s2, len1 + len2 + 1);
	return (string);
}
/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	test_ft_strjoin()
{
	char	string[] = "1234";
	char	string2[] = "5678";
	char	*join;

	join = ft_strjoin(string, string2);
	if (strcmp(join, "12345678") != 0)
		return (1);
	free(join);
	return (0);
}
int	main(void)
{
	if (test_ft_strjoin() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strjoin());
	printf("\n");
}
 */