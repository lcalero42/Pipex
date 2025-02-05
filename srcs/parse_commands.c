/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:07:32 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/05 22:48:24 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	free_tmps(char *tmp_1, char *tmp_2);

void	parse_commands(char **av, t_data *data)
{
	char	*tmp_1;
	char	*tmp_2;

	ft_bzero(data, sizeof(t_data));
	data->infile = av[1];
	data->commands_1 = ft_split(av[2], ' ');
	data->commands_2 = ft_split(av[3], ' ');
	tmp_1 = ft_strdup(data->commands_1[0]);
	tmp_2 = ft_strdup(data->commands_2[0]);
	if (!tmp_1 || !tmp_2)
	{
		free_data(data);
		free_tmps(tmp_1, tmp_2);
		return ;
	}
	free(data->commands_1[0]);
	data->commands_1[0] = ft_strjoin("/bin/", tmp_1);
	free(data->commands_2[0]);
	data->commands_2[0] = ft_strjoin("/bin/", tmp_2);
	data->outfile = av[4];
	free_tmps(tmp_1, tmp_2);
}

static void	free_tmps(char *tmp_1, char *tmp_2)
{
	if (tmp_1)
		free(tmp_1);
	if (tmp_2)
		free(tmp_2);
}

void	ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i])
			free(res[i]);
		i++;
	}
	free(res);
}
