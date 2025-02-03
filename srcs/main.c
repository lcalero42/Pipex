/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:24:39 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 16:30:52 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av)
{
	pid_t 	pid;
	char	**commands;
	char 	*envp[] = {NULL};

	commands = parse_commands(av, ac);
	pid = fork();
	if (pid == 0)
	{
		execve(commands[0], commands, envp);
	}
	wait(NULL);
	ft_free(commands);
	return (0);
}
