/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:45:14 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/04 15:21:31 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse_line.h"

t_cmd	*parse_line(char const *line)
{
	t_list		*tokens;
	// t_cmdtree	*cmdtree;
	// int		return_check;

	if (!line)
		return (NULL);
	tokens = tokenize(line);
	// cmdtree = create_cmdtree(tokens);
	// return_check = expand_envs(cmdtree);
	// return_check = expand_wilds(cmdtree);
	// return_check = remove_quotes(cmdtree);
}