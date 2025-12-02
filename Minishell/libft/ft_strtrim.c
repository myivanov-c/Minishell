/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:52:39 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:14:28 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	int		len;
	int		start;
	int		end;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len && ft_strchr(set, (char) s1[i]) != 0)
		i++;
	start = i;
	i = len;
	while (i > start && ft_strchr(set, (char) s1[i - 1]) != 0)
		i--;
	end = i;
	len = end - start;
	string = (char *) malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, &s1[start], len + 1);
	return (string);
}
/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	test_ft_strtrim()
{
	char	string[] = "41 41224334 1 ";
	char	set[] = "14 ";
	char	*trim;

	trim = ft_strtrim(string, set);
	if (strcmp(trim, "22433") != 0)
		return (1);
	free(trim);
	return (0);
}
int	main(void)
{
	if (test_ft_strtrim() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strtrim());
	printf("\n");
}
 */