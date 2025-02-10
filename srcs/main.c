/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:24:39 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/10 12:39:36 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
		return (1);
	parse_commands(av, &data, envp);
	execute(&data, envp);
	ft_free(data.commands_1);
	ft_free(data.commands_2);
	return (0);
}
