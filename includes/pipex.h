/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:47 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/05 22:41:25 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
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

void	parse_commands(char **av, t_data *data);

pid_t	execute(t_data *data, char **envp);

void	ft_free(char **res);

void	free_data(t_data *data);

#endif