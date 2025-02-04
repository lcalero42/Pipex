/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:29:29 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/04 12:40:45 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

pid_t	execute(t_data data, char **envp)
{
	pid_t 	pid;
	
	pid = fork();
	if (pid == 0)
	{
		execve(data.commands_1[0], data.commands_1, envp);
	}
	wait(NULL);
	return (pid);
}
