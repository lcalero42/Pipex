/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:37:47 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/04 12:39:57 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	char	**commands_1;
	char	**commands_2;
}	t_data;


void	parse_commands(char **av, t_data *data);

pid_t	execute(t_data data, char **envp);

void	ft_free(char **res);

#endif