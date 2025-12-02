/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:39:09 by causilva          #+#    #+#             */
/*   Updated: 2025/04/21 16:23:13 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (!f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
#include <stdio.h>
#include <string.h>
void	f(unsigned int i, char *c)
{
	*c += i;
}
int	test_ft_striteri()
{
	char	iteri[] = "01234";

	ft_striteri(iteri, &f);
	if (strcmp(iteri, "02468") != 0)
		return (1);
	return (0);
}
int	main(void)
{
	if (test_ft_striteri() == 0)
		printf("OK");
	else
		printf("!KO! - %d", test_ft_striteri());
	printf("\n");
}
 */