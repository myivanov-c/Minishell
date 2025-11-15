/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:45:14 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/15 11:45:19 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"
#include "parse_line.h"

void	print_tokens_flat(t_list *tokens)
{
	t_list	*tmp = tokens;

	while (tmp)
	{
		printf("%s", ((t_token *)tmp->content)->str);
		if (tmp->next)
			printf(" ");
		tmp = tmp->next;
	}
}

void	print_cmdtree_simple(t_cmdtree *node, int depth)
{
	int	i;

	if (!node)
		return ;

	// Indentação visual
	for (i = 0; i < depth; i++)
		printf("    "); // 4 espaços por nível

	// Print tipo + tokens
	printf("Type %d | ", node->type);
	print_tokens_flat(node->tokens);
	printf("\n");

	// Recursividade para os filhos (aumentando a profundidade)
	print_cmdtree_simple(node->child1, depth + 1);
	print_cmdtree_simple(node->child2, depth + 1);
}



t_cmd	*parse_line(t_list  *tokens)
{
	t_cmdtree	*cmdtree;
	//int		return_check;
	//tokens = tokenize(line);
    //print_list(tokens);
	cmdtree = create_cmdtree(tokens);
    if (cmdtree)
		print_cmdtree_simple(cmdtree, 0); 
	//return_check = expand_envs(cmdtree);
	//return_check = expand_wilds(cmdtree);
	//return_check = remove_quotes(cmdtree);
    return (NULL);
}