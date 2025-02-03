/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:07:32 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 16:31:48 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char **parse_commands(char **av, int ac)
{
	int	i;
	char **res;
	char *tmp;

	i = 0;
	res = malloc(sizeof(char *) * (ac));
	tmp = ft_strjoin("/bin/", av[1]);
	res[i] = ft_strdup(tmp);
	free(tmp);
	i++;
	while (i < ac - 1)
	{	
		res[i] = ft_strdup(av[i + 1]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_free(char **res)
{
    int     i;
    
	i = 0;
    while (res[i])
    {
        if (res[i])
            free(res[i]);
        i++;
    }
    free(res);
}
