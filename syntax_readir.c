/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_readir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:53:07 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/26 19:11:31 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_word_token(char *s)
{
    return (s
        && ft_strcmp(s, "(") != 0
        && ft_strcmp(s, ")") != 0
        && !is_operator_str(s)
        && !is_redirection_token(s));
}

static int redir_followup_status(t_list *node)
{
    t_list  *nextn;
    t_token *next;

    nextn = node->next;
    if (!nextn)
        return (2); //newline
    next = (t_token *)nextn->content;
    if (!next || !next->str)
        return (2);
    if (!is_word_token(next->str))
        return (1);
    return (0);
}

int has_invalid_redirection_sequences(t_list *tokens)
{
    t_token *tk;
    int     st;

    while (tokens)
    {
        tk = (t_token *)tokens->content;
        if (tk && tk->str && is_redirection_token(tk->str))
        {
            st = redir_followup_status(tokens);
            if (st)
                return (st);
        }
        tokens = tokens->next;
    }
    return (0);
}
