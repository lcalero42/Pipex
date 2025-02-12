/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:29:29 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/12 11:56:45 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	close_fds(t_data *data);
static void	exec_p1(t_data *data, char **envp);
static void	exec_p2(t_data *data, char **envp);
static void	init_data(t_data *data);

pid_t	execute(t_data *data, char **envp)
{
	int	status;
	int	exit_code;
	int	pid;

	init_data(data);
	exec_p1(data, envp);
	exec_p2(data, envp);
	pid = wait(&status);
	while (pid > 0)
	{
		if (pid == data->pid_2)
			exit_code = status;
		pid = wait(&status);
	}
	if (WIFSIGNALED(exit_code))
	{
		exit_code = 128 + WTERMSIG(exit_code);
		free_data(data);
		exit(exit_code);
	}
	else if (WIFEXITED(exit_code))
		exit_code = WEXITSTATUS(exit_code);
	free_data(data);
	exit(exit_code);
	return (data->pid_2);
}

static void	exec_p1(t_data *data, char **envp)
{
	data->pid_1 = fork();
	if (data->pid_1 == -1)
	{
		free_data(data);
		exit(1);
	}
	if (data->pid_1 == 0)
	{
		if (data->fd_in < 0)
		{
			free_data(data);
			perror_exit("Error opening infile", 2);
		}
		dup2(data->fd_in, 0);
		dup2(data->pipefd[1], 1);
		close_fds(data);
		execve(data->commands_1[0], data->commands_1, envp);
		if (access(data->commands_1[0], F_OK))
		{
			free_data(data);
			perror_exit("Command not found", 127);
		}
	}
	close(data->pipefd[1]);
}

static void	exec_p2(t_data *data, char **envp)
{
	data->pid_2 = fork();
	if (data->pid_2 == -1)
	{
		free_data(data);
		exit(1);
	}
	if (data->pid_2 == 0)
	{
		if (data->fd_out < 0)
		{
			free_data(data);
			perror_exit("Error opening outfile", 1);
		}
		dup2(data->pipefd[0], 0);
		dup2(data->fd_out, 1);
		close_fds(data);
		execve(data->commands_2[0], data->commands_2, envp);
		if (access(data->commands_2[0], F_OK))
		{
			free_data(data);
			perror_exit("Command not found", 127);
		}
	}
	close(data->pipefd[0]);
}

static void	init_data(t_data *data)
{
	data->fd_in = open(data->infile, O_RDONLY);
	data->fd_out = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe(data->pipefd) == -1)
	{
		close(data->fd_in);
		close(data->fd_out);
		free_data(data);
		perror_exit("Error executing pipe", 1);
	}
}

static void	close_fds(t_data *data)
{
	close(data->fd_in);
	close(data->fd_out);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}
