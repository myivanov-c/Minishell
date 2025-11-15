/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wilds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:52:59 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/15 11:44:56 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse_line.h"

static int	expand_wilds_tokenlst(t_list *tokens);

int	expand_wilds(t_cmdtree *cmdtree)
{
	if (!cmdtree)
		return (-1);
	if (cmdtree->type == 4)
		return (expand_wilds_tokenlst(cmdtree->tokens));
	if (cmdtree->child1)
		if (expand_wilds(cmdtree->child1) == -1)
			return (-1);
	if (cmdtree->child2)
		if (expand_wilds(cmdtree->child2) == -1)
			return (-1);
	return (0);
}

static int	expand_wilds_tokenlst(t_list *tokens)
{
	
}