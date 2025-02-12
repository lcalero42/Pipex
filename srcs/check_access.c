/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:24:45 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/12 16:05:00 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_access(char *command, t_data *data)
{
	if (access(command, F_OK))
	{
		free_data(data);
		perror_exit("Pipex Error", 127);
	}
	else if (access(command, X_OK))
	{
		free_data(data);
		perror_exit("Pipex Error", 126);
	}
	exit(EXIT_FAILURE);
}
