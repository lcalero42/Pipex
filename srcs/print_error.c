/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:46:57 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/12 17:08:34 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*This function prints the right error related to the
exit code passed in parameter*/
void	perror_exit(const char *message, int exit_code)
{
	if (exit_code == 127)
	{
		ft_putstr_fd("Pipex Error: Command not found\n",
			STDERR_FILENO);
		exit(exit_code);
		return ;
	}
	perror(message);
	exit(exit_code);
}
