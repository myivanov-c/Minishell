/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:30:18 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/29 17:42:31 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wildcards.h"

void	free_array_split(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_array_n(char **arr, int n)
{
	int	i;

	if (!arr || n <= 0)
		return ;
	i = 0;
	while (i < n)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	sort_array(char **arr)
{
	int		i;
	int		swapped;
	char	*temp;

	if (!arr || !arr[0])
		return ;
	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (arr[i] && arr[i + 1])
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

int	check_presence_of_wildcard(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '*')
			result = 1;
		i++;
	}
	return (result);
}
