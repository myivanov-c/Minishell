/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:23:13 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:34:58 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	return (c + ((c >= 'A' && c <= 'Z') * 32));
}
/* 
#include <stdio.h>
#include <ctype.h>
int	test_ft_tolower()
{
	int	i;

	i = 0;
	while (i <= 127)
	{
		if ((ft_tolower(i) == 0) != (tolower(i) == 0))
			return (1);
		i++;
	}
	return (0);
}
int	main(void)
{
	if (test_ft_tolower() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_tolower());
	printf("\n");
}
 */