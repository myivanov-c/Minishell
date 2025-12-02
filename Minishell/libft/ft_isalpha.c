/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:37:13 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:22:44 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'));
}
/* 
#include <stdio.h>
int	main(void)
{
	int	i;

	i = -500;
	while (i <= 500)
	{
		if (ft_isalpha(i))
			printf("%c", i);
		i++;
	}
	printf("\n");
	return (0);
}
 */