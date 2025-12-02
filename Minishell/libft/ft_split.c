/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:53:07 by causilva          #+#    #+#             */
/*   Updated: 2025/04/22 11:37:21 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	count_words(char const *s, char c)
{
	int		num_words;
	int		i;

	num_words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			num_words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (num_words);
}

static void	fill_array(char **array, char const *s, char c)
{
	int		array_i;
	int		i;
	int		start;

	array_i = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		array[array_i] = ft_substr(s, start, i - start);
		if (!array[array_i])
		{
			free_array(array);
			return ;
		}
		array_i++;
	}
	array[array_i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (malloc(0));
	array = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	fill_array(array, s, c);
	return (array);
}
/* 
#include <stdio.h>
#include <string.h>
int	test_ft_split()
{
	char	string[] = "  123 1234  ";
	char	**split;

	split = ft_split(string, ' ');
	if (strcmp(split[0], "123") != 0
		|| strcmp(split[1], "1234") != 0
		|| (split[2] != NULL))
		return (1);
	free_array(split);
	return (0);
}
int	main(void)
{
	if (test_ft_split() == 0)
		printf("OK");
	else
		printf("!KO!");
	printf("\n");
}
 */