/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:24:39 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/04 15:55:58 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av)
{
	t_data	data;
	char 	*envp[] = {NULL};

	if (ac != 5)
		return (1);
	parse_commands(av, &data);
	execute(&data, envp);
	ft_free(data.commands_1);
	ft_free(data.commands_2);
	return (0);
}
