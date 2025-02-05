/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:29:29 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/05 02:00:56 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	close_fds(t_data *data);
static void	exec_p1(t_data *data, char **envp);
static void	exec_p2(t_data *data, char **envp);
static void	init_data(t_data *data);

pid_t	execute(t_data *data, char **envp)
{
	init_data(data);
	exec_p1(data, envp);
	exec_p2(data, envp);
	return (data->pid_2);
}

static void	exec_p1(t_data *data, char **envp)
{
	data->pid_1 = fork();
	if (data->pid_1 == 0)
	{
		dup2(data->fd_in, 0);
		dup2(data->pipefd[1], 1);
		close_fds(data);
		execve(data->commands_1[0], data->commands_1, envp);
		exit(127);
	}
	close(data->pipefd[1]);
}

static void	exec_p2(t_data *data, char **envp)
{
	data->pid_2 = fork();
	if (data->pid_2 == 0)
	{
		dup2(data->pipefd[0], 0);
		dup2(data->fd_out, 1);
		close_fds(data);
		execve(data->commands_2[0], data->commands_2, envp);
	}
	close(data->pipefd[0]);
}

static void	init_data(t_data *data)
{
	data->fd_in = open(data->infile, O_RDONLY);
	if (data->fd_in < 0)
	{
		perror("Error reading infile");
		exit(2);
	}
	data->fd_out = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_out < 0)
	{
		perror("Error opening outfile");
		exit(3);
	}
	if (pipe(data->pipefd) == -1)
	{
		perror("Pipe failed");
		close(data->fd_in);
		close(data->fd_out);
		exit(1);
	}
}

static void	close_fds(t_data *data)
{
	close(data->fd_in);
	close(data->fd_out);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}
