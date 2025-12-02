/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:36:06 by causilva          #+#    #+#             */
/*   Updated: 2025/12/01 20:59:47 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell_loop(t_vars *vars);
static int	init_vars(t_vars *vars, char **envp);
void		signal_handler(int sig);

int	g_signal;

int	main(int argc, char **argv, char **envp)
{
	struct sigaction	act;
	t_vars				vars;

	(void)argv;
	if (argc != 1)
		return (1);
	act.sa_handler = &signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);
	signal(SIGQUIT, SIG_IGN);
	if (init_vars(&vars, envp) == -1)
		return (1);
	while (1)
		minishell_loop(&vars);
	return (0);
}

static void	minishell_loop(t_vars *vars)
{
	g_signal = -1;
	vars->cmdtree = get_cmdtree(vars);
	if (vars->cmdtree)
	{
		g_signal = 0;
		exec_cmdtree(vars->cmdtree, vars);
		vars->last_exit_status = vars->cmdtree->exit_status;
	}
	free_cmdtree(vars->cmdtree);
	vars->cmdtree = NULL;
}

static int	init_vars(t_vars *vars, char **envp)
{
	vars->cmdtree = NULL;
	vars->envp = malloc(1 * sizeof(char *));
	if (!vars->envp)
		return (-1);
	vars->envp[0] = NULL;
	builtin_export(envp, 1, vars);
	vars->heredocs = malloc(1 * sizeof(int));
	if (!vars->heredocs)
		return (free(vars->envp), -1);
	vars->heredocs[0] = -1;
	vars->last_exit_status = 0;
	return (0);
}

void	signal_handler(int sig)
{
	if (g_signal == -1)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		g_signal = sig;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}
