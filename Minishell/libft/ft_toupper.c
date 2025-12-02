/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:21:31 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 15:35:05 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	return (c - ((c >= 'a' && c <= 'z') * 32));
}
/* 
#include <stdio.h>
#include <ctype.h>
int	test_ft_toupper()
{
	int	i;

	i = 0;
	while (i <= 127)
	{
		if ((ft_toupper(i) == 0) != (toupper(i) == 0))
			return (1);
		i++;
	}
	return (0);
}
int	main(void)
{
	if (test_ft_toupper() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_toupper());
	printf("\n");
}
 */