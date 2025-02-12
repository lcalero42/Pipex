/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:46:57 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/12 12:48:42 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/pipex.h"

void	perror_exit(const char *message, int exit_code)
{
	if (exit_code == 127)
	{
		ft_putstr_fd("Pipex Error : Command not found\n",
			STDERR_FILENO);
		exit(exit_code);
		return ;
	}
	ft_putstr_fd((char *)message, STDERR_FILENO);
	write(STDERR_FILENO, ": ", 2);
	ft_putstr_fd((char *)strerror(errno), STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit(exit_code);
}
