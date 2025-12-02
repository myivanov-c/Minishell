/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdtree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:09:58 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 20:30:23 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMDTREE_H
# define EXEC_CMDTREE_H

# include "../minishell.h"

int		expand(t_list **tokens_ptr, t_vars *vars);
t_list	*get_expanded_env(t_token *token, t_vars *vars);
t_list	*get_expanded_wild(t_token *token);
char	**total_filtered_outcomes_multi(char *str);
void	free_array_split(char **arr);

int		exec_parentheses(t_cmdtree *cmdtree, t_vars *vars);
int		exec_and(t_cmdtree *cmdtree, t_vars *vars);
int		exec_or(t_cmdtree *cmdtree, t_vars *vars);
int		exec_pipe(t_cmdtree *cmdtree, t_vars *vars);
int		exec_cmd(t_cmdtree *cmdtree, t_vars *vars);

int		redirect(t_cmdtree *cmdtree, t_vars *vars);

int		builtin(char **argv, int fd_output, t_vars *vars);
int		is_builtin(char *name);
int		builtin_cd(char **argv);
int		builtin_echo(char **argv, int fd_output);
int		builtin_env(char **envp, int fd_output);
int		special_env(char **envp, int fd_output);
int		builtin_exit(char **argv, t_vars *vars);
int		builtin_export(char **argv, int fd_output, t_vars *vars);
int		builtin_pwd(int fd_output);
int		builtin_unset(char **argv, char **envp);

void	memory_cleanup(t_vars vars);
void	io_cleanup(t_vars vars);

#endif