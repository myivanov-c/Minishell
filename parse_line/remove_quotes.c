/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:46:54 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/15 11:46:03 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse_line.h"

static int	remove_quotes_tokenlst(t_list *tokens);

int	remove_quotes(t_cmdtree *cmdtree)
{
	if (!cmdtree)
		return (-1);
	if (cmdtree->type == 4)
		return (remove_quotes_tokenlst(cmdtree->tokens));
	if (cmdtree->child1)
		if (remove_quotes(cmdtree->child1) == -1)
			return (-1);
	if (cmdtree->child2)
		if (remove_quotes(cmdtree->child2) == -1)
			return (-1);
	return (0);
}

static int	remove_quotes_tokenlst(t_list *tokens)
{
	
}