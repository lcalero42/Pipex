/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:29:29 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/12 17:04:26 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	close_fds(t_data *data);
static void	exec_p1(t_data *data, char **envp);
static void	exec_p2(t_data *data, char **envp);
static void	init_data(t_data *data);

/*This function is the praent process that will execute
the two child process and wait for them to finish to exit
with the right exit code (the exit code of pid_2)*/
pid_t	execute(t_data *data, char **envp)
{
	int	status;
	int	exit_code;

	init_data(data);
	exec_p1(data, envp);
	exec_p2(data, envp);
	waitpid(data->pid_1, NULL, 0);
	if (waitpid(data->pid_2, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_code = 128 + WTERMSIG(status);
	}
	free_data(data);
	exit(exit_code);
	return (data->pid_2);
}

/*This function executes the first command in the first
child process and writes its result in the pipe*/
static void	exec_p1(t_data *data, char **envp)
{
	data->pid_1 = fork();
	if (data->pid_1 == -1)
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	if (data->pid_1 == 0)
	{
		if (data->fd_in < 0)
		{
			free_data(data);
			perror_exit("Pipex Error", EXIT_FAILURE);
		}
		dup2(data->fd_in, 0);
		dup2(data->pipefd[1], 1);
		close_fds(data);
		execve(data->commands_1[0], data->commands_1, envp);
		check_access(data->commands_1[0], data);
	}
	close(data->pipefd[1]);
}

/*This function executes the second command in the second
child process and writes its result in the outfile*/
static void	exec_p2(t_data *data, char **envp)
{
	data->pid_2 = fork();
	if (data->pid_2 == -1)
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	if (data->pid_2 == 0)
	{
		if (data->fd_out < 0)
		{
			free_data(data);
			perror_exit("Pipex Error", EXIT_FAILURE);
		}
		dup2(data->pipefd[0], 0);
		dup2(data->fd_out, 1);
		close_fds(data);
		execve(data->commands_2[0], data->commands_2, envp);
		check_access(data->commands_2[0], data);
	}
	close(data->pipefd[0]);
}

/*This function initialize the data that we need in
all the processes and create the pipe that we will need
to make the data flow between processes*/
static void	init_data(t_data *data)
{
	data->fd_in = open(data->infile, O_RDONLY);
	data->fd_out = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe(data->pipefd) == -1)
	{
		close(data->fd_in);
		close(data->fd_out);
		free_data(data);
		perror_exit("Error executing pipe", EXIT_FAILURE);
	}
}

/*This function closes all the file descriptors*/
static void	close_fds(t_data *data)
{
	close(data->fd_in);
	close(data->fd_out);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}
