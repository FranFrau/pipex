/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:33:58 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/13 18:37:57 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	file_opener(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0644);
	if (file == -1)
		print_exit_error(OPEN_ERROR_TXT, OPEN_ERROR);
	return (file);
}

void	child_process(char *argv, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		print_exit_error(PIPE_ERROR_TXT, PIPE_ERROR);
	pid = fork();
	if (pid == -1)
		print_exit_error(FORK_ERROR_TXT, FORK_ERROR);
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	bonus2(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (argc < 6)
		print_error(ft_strjoin(FEW_ARGS_TXT, ARG2_ERROR_TXT), ARG2_ERROR);
	if (pipe(fd) == -1)
		print_exit_error(PIPE_ERROR_TXT, PIPE_ERROR);
	pid = fork();
	if (!pid)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
	else
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strcmp(line, limiter))
				exit(0);
			write(fd[1], line, ft_strlen(line));
		}
	}
}
