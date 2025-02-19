/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:24:39 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/13 15:07:39 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5 || !av[2][0] || !av[3][0])
		return (0);
	parse_commands(av, &data, envp);
	execute(&data, envp);
	free_data(&data);
	return (0);
}
