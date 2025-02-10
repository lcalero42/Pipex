/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:07:32 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/10 16:51:04 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*find_right_path(char **paths, char *command);
static char	*find_command_path(char *command, char **envp);

void	parse_commands(char **av, t_data *data, char **envp)
{
	char	*cmd1_path;
	char	*cmd2_path;

	ft_bzero(data, sizeof(t_data));
	data->infile = av[1];
	data->commands_1 = ft_split(av[2], ' ');
	data->commands_2 = ft_split(av[3], ' ');
	cmd1_path = find_command_path(data->commands_1[0], envp);
	cmd2_path = find_command_path(data->commands_2[0], envp);
	if (!cmd1_path || !cmd2_path)
	{
		free_data(data);
		free(cmd1_path);
		free(cmd2_path);
		perror_exit("Command not found", 127);
	}
	free(data->commands_1[0]);
	data->commands_1[0] = cmd1_path;
	free(data->commands_2[0]);
	data->commands_2[0] = cmd2_path;
	data->outfile = av[4];
}

static char	*find_command_path(char *command, char **envp)
{
	int		i;
	char	*path_env;
	char	**paths;
	char	*full_path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path_env = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	full_path = find_right_path(paths, command);
	ft_free(paths);
	return (full_path);
}

static char	*find_right_path(char **paths, char *command)
{
	char	*full_path;
	char	*tmp;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, command);
		free(tmp);
		if (!access(full_path, F_OK))
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
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
