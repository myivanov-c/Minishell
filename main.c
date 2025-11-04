/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykytaivanov <mykytaivanov@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:38:41 by mykytaivano       #+#    #+#             */
/*   Updated: 2025/11/04 15:09:18 by mykytaivano      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	t_cmd	*cmd_array;

	line = readline(">> ");
	while (line)
	{
		if (*line)
		{
			add_history(line);
			printf("line: %s\n", line);
			cmd_array = parse_line(line);
			if (cmd_array)
			{
				//run_commands(cmd_array);
				//free_cmd_array(cmd_array);
			}
		}
		free (line);
		line = readline(">> ");
	}
	clear_history();
	return (0);
}