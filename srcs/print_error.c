/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:46:57 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/10 14:28:07 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/pipex.h"

void	perror_exit(const char *message, int exit_code)
{
	ft_putstr_fd((char *)message, STDERR_FILENO);
	write(STDERR_FILENO, ": ", 2);
	ft_putstr_fd((char *)strerror(errno), STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit(exit_code);
}
