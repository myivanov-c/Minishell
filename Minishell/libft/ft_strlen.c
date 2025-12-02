/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:12:57 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:02:27 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/* 
#include <stdio.h>
#include <string.h>
int	test_ft_strlen()
{
	if (ft_strlen("") != strlen(""))
		return (1);
	if (ft_strlen("42") != strlen("42"))
		return (2);
	if (ft_strlen("asdv awfaf") != strlen("asdv awfaf"))
		return (3);
	return (0);
}
int	main(void)
{
	if (test_ft_strlen() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_strlen());
	printf("\n");
}
 */