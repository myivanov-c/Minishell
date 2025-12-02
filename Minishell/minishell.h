/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myivanov <myivanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:09:58 by causilva          #+#    #+#             */
/*   Updated: 2025/12/02 12:06:36 by myivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define _GNU_SOURCE

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include "libft/libft.h"
# include <sys/wait.h>

//# include "get_cmdtree/parse_line.h"
# include "token_utils/token_utils.h"
//# include "exec_cmdtree/expand/Wildcards/wildcards.h"

extern int	g_signal;

typedef struct s_token
{
	char	*str;
	char	*quoted;
	int		control;
	int		fd_heredoc;
}	t_token;
// quoted 0 = normal   quoted 39 (') = literal   quoted 34 (") = half literal
// control 0 = normal   control 1 ='('   control 2 = ')'
// control 3 = '&&'   control 4 = '||'   control 5 = '|'
// control 6 = '<<'   control 7 = '<'   control 8 = '>>'   control 9 = '>'
// control 10 = redirect_name

typedef struct s_cmdtree
{
	struct s_list		*tokens;
	int					type;
	int					fd_input;
	int					fd_pipe;
	int					fd_output;
	int					is_local_fd_input;
	int					is_local_fd_output;
	int					exit_status;
	struct s_cmdtree	*parent;
	struct s_cmdtree	*child1;
	struct s_cmdtree	*child2;
}	t_cmdtree;
// type 0 = ()    type 1 = &&    type 2 = ||    type 3 = |    type 4 = cmd

typedef struct s_vars
{
	t_cmdtree	*cmdtree;
	char		**envp;
	int			*heredocs;
	int			last_exit_status;
}	t_vars;

t_cmdtree	*get_cmdtree(t_vars *vars);
int			exec_cmdtree(t_cmdtree *cmdtree, t_vars *vars);
int			builtin_export(char **argv, int fd_output, t_vars *vars);

void		memory_cleanup(t_vars vars);
void		free_cmdtree(t_cmdtree *cmdtree);
void		io_cleanup(t_vars vars);
void		io_cleanup_cmdtree(t_cmdtree *cmdtree);
t_list		*jump_parenthesis(t_list *node);

#endif