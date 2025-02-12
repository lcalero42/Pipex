/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:47 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/12 15:27:35 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# define PATH "/bin/"

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	char	**commands_1;
	char	**commands_2;
	int		pipefd[2];
	int		fd_in;
	int		fd_out;
	pid_t	pid_1;
	pid_t	pid_2;
}	t_data;

void	parse_commands(char **av, t_data *data, char **envp);

pid_t	execute(t_data *data, char **envp);

void	ft_free(char **res);

void	free_data(t_data *data);

void	perror_exit(const char *message, int exit_code);

void	check_access(char *command, t_data *data);

#endif