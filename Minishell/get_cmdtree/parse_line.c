/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:45:14 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/12/02 12:10:09 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse_line.h"

/*void	print_tokens_flat(t_list *tokens)
{
	while (tokens)
	{
		printf("%s", ((t_token *)tokens->content)->str);
		if (tokens->next)
			printf(" ");
		tokens = tokens->next;
	}
}

void	print_cmdtree_simple(t_cmdtree *node, int depth)
{
	int	i;

	if (!node)
		return ;
	i = 0;
	while (i < depth)
	{
		printf("    ");
		i++;
	}
	printf("Type %d | ", node->type);
	print_tokens_flat(node->tokens);
	printf("\n");
	print_cmdtree_simple(node->child1, depth + 1);
	print_cmdtree_simple(node->child2, depth + 1);
}*/

t_cmdtree	*parse_line(t_list *tokens)
{
	t_cmdtree	*cmdtree;

	if (!tokens)
		return (NULL);
	cmdtree = create_cmdtree(tokens);
	ft_lstclear(&tokens, free_token);
	if (!cmdtree)
		return (NULL);
	return (cmdtree);
}
