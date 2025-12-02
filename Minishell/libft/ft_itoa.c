/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:53:32 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:22:56 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_numlen(long n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_string(char *string, long n)
{
	int	len;

	if (n < 0)
	{
		string[0] = '-';
		fill_string(&string[1], -n);
		return ;
	}
	len = get_numlen(n);
	string[len] = '\0';
	while (--len >= 0)
	{
		string[len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*string;

	string = malloc((get_numlen(n) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	fill_string(string, n);
	return (string);
}
/* 
#include <stdio.h>
#include <string.h>
int	test_ft_itoa()
{
	char	*string;

	string = ft_itoa(0);
	if (strcmp(string, "0") != 0)
		return (1);
	free(string);
	string = ft_itoa(42);
	if (strcmp(string, "42") != 0)
		return (2);
	free(string);
	string = ft_itoa(-2147483648);
	if (strcmp(string, "-2147483648") != 0)
		return (3);
	free(string);
	string = ft_itoa(2147483647);
	if (strcmp(string, "2147483647") != 0)
		return (4);
	free(string);
	return (0);
}
int	main(void)
{
	if (test_ft_itoa() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_itoa());
	printf("\n");
}
 */