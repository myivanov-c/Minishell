/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:46:05 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/19 12:56:23 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_LINE_H
# define PARSE_LINE_H

# include <stdlib.h>
# include <stdio.h>

#define REDIR_IN 0
#define REDIR_OUT 1
#define REDIR_APPEND 2
#define REDIR_HEREDOC 3

typedef struct s_token
{
	char	*str;
	char	*quote_flags;
}	t_token;

typedef struct s_redirs
{
    int     type;
    char    *file;
}   t_redirs;


typedef struct s_split_result
{
	t_list	*left;
	t_list	*right;
}	t_split_result;

typedef struct s_cmdtree
{
	struct s_list		*tokens;
	int					type;
	int					fd_input;
	int					fd_pipe;
	int					fd_output;
	int					output_append_mode;
	int					exit_status;
	int					exec_status;
	struct s_cmdtree	*parent;
	struct s_cmdtree	*child1;
	struct s_cmdtree	*child2;
	struct s_cmd		*cmd;
}	t_cmdtree;

// quote_flags 0 = normal
// quote_flags 39 (') = literal
// quote_flags 34 (") = half literal

t_list		*tokenize(char const *line);

//t_cmdtree	*create_cmdtree(t_list *tokens);
//int			expand_envs(t_cmdtree *cmdtree);
//int			expand_wilds(t_cmdtree *cmdtree);
//int			remove_quotes(t_cmdtree *cmdtree);

t_token		*new_token(char const *line, int len);
t_token		*dup_token(t_token *old_token);
int			fill_token_flags(t_token *token);
void		free_token(void *token);
void    print_list(t_list *list);


t_cmdtree	*create_cmdtree(t_list *tokens);
t_cmdtree	*cmdtree_new_node(t_list *tokens);
t_list	*get_split_point(t_list *tokens, int type);
t_list	*get_tokens_left(t_list *tokens, t_list *split_point);
t_list	*get_tokens_right(t_list *split_point);

int     ft_strcmp(char *s1, char *s2);
void	print_cmdtree_simple(t_cmdtree *node, int depth);
void	cmdtree_clear(t_cmdtree *tree);
void	print_tokens_flat(t_list *tokens);

int     ft_isspace(char c);



int	extract_token_len(const char *line);

#endif