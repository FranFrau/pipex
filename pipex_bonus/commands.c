/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:28:52 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/13 17:39:31 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_cmd_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (!access(path, F_OK))
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *argv, char **env)
{
	char	**commands;
	char	*path;

	commands = ft_split(argv, ' ');
	path = find_cmd_path(commands[0], env);
	if (!path)
	{
		free_matrix(commands);
		print_exit_error(PATH_ERROR_TXT, PATH_ERROR);
	}
	if (execve(path, commands, env) == -1)
		print_exit_error(EXEC_ERROR_TXT, EXEC_ERROR);
}
