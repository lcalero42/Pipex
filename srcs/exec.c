/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:29:29 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/04 16:53:39 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

pid_t	execute(t_data *data, char **envp)
{
	int		pipefd[2];
	pid_t 	pid_1;
	pid_t 	pid_2;
	int		fd_in;
	int		fd_out;
	
	fd_in = open(data->infile, O_RDONLY);
	if (fd_in < 0)
	{
		perror("Error reading fd_in");
		return (-1);
	}
	fd_out = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("Error opening fd_out");
		return (-1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("Pipe failed");
		close(fd_in);
		close(fd_out);
		return (-1);
	}
	pid_1 = fork();
	if (pid_1 == 0)
	{
		dup2(fd_in, 0);
		dup2(pipefd[1], 1);
		close(fd_in);
		close(fd_out);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(data->commands_1[0], data->commands_1, envp);
	}
	pid_2 = fork();
	if (pid_2 == 0)
	{
		dup2(pipefd[0], 0);
		dup2(fd_out, 1);
		close(fd_in);
		close(fd_out);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(data->commands_2[0], data->commands_2, envp);
	}
	return (pid_2);
}
