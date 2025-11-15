/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:43:06 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/15 11:47:44 by mykytaivano      ###   ########.fr       */
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
}	t_cmd;

// type 0 = ()    type 1 = |    type 2 = &&    type 3 = ||    type 4 = cmd
// exec_status 0 = not run    exec_status 1 = running    exec_status 2 = done

typedef struct s_cmdtree_simple
{
	struct s_list		*tokens;
	int					type;
	struct s_cmdtree	*parent;
	struct s_cmdtree	*child1;
	struct s_cmdtree	*child2;
}	t_cmdtree_simple;

t_cmd     *parse_line(t_list *tokens);

int     ft_strcmp(char *s1, char *s2);

void	free_cmd_array(t_cmd *cmd_array);
void	free_str_array(char **str_array);

#endif
// (echo a | echo b) > test | echo c

//               (type 3 |) "(echo a | echo b) > test | echo c"

// (type 0)"(echo a | echo b) > test"                        (type 4 )"echo c"

// (type 3 |)"echo a | echo b" 

// (type 4 )"echo a"     (type 4 )"echo b" 