/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:54:57 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/04 14:56:46 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_data(t_data *data)
{
	if (data->commands_1)
		ft_free(data->commands_1);
	if (data->commands_2)
		ft_free(data->commands_2);
}
