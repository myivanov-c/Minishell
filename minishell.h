/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:43:06 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/26 19:12:47 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft/libft.h"         // <- inclui as funções tipo ft_strlen, etc
# include "parse_line/parse_line.h"

typedef struct s_cmd
{
	char	*cmd_full_str;
	char	*cmd_name;
	char	**cmd_options;
	char	**cmd_args;
    t_list  *redirs;
}	t_cmd;

typedef struct s_cmdtree_simple
{
	struct s_list		*tokens;
	int					type;
	struct s_cmdtree	*parent;
	struct s_cmdtree	*child1;
	struct s_cmdtree	*child2;
}	t_cmdtree_simple;

t_cmd     *parse_line(t_list *tokens);
int	is_redirection_token(char *str);

int     ft_strcmp(char *s1, char *s2);

void	free_cmd_array(t_cmd *cmd_array);
void	free_str_array(char **str_array);
void	free_one_cmd(t_cmd *cmd);
int	is_operator_str(char *str);



//parse_simple_cmd.c

t_cmd	*parse_simple_cmd(t_list *tokens);
t_cmd	*init_cmd(void);
int	add_arg(t_cmd *cmd, char *new_str);
int	parse_cmd_token(t_token *token, t_cmd *cmd);
int	parse_cmd_redir(t_list **tokens, t_cmd *cmd);
int	get_redir_type(char *str);
int	is_redirection_token(char *str);

//syntax_readir.c
int has_invalid_redirection_sequences(t_list *tokens);
int is_word_token(char *s);

#endif