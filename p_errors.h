/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_errors.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 11:15:51 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/13 14:30:35 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_ERRORS_H
# define P_ERRORS_H

# define FEW_ARGS_TXT "Too few arguments. Use "
# define ARG1_ERROR_TXT "./pipex <file1> <cmd1> <cmd2> <file2>\n"
# define ARG2_ERROR_TXT "./pipex here_doc LIMITER <cmd1> <cmd2> <file>\n"
# define PIPE_ERROR_TXT "Pipe error, i can't create a pipe.\nError"
# define OPEN_ERROR_TXT "File error, i can't open the file.\nError"
# define PATH_ERROR_TXT "Path error, i can't find the correct path.\nError"
# define EXEC_ERROR_TXT "Command error, i can't execute the command.\nError"
# define FORK_ERROR_TXT "Fork error, i can't fork the pid.\nError"

typedef enum e_errors
{
	ARG1_ERROR = 1,
	ARG2_ERROR = 1,
	PIPE_ERROR = -1,
	OPEN_ERROR = 1,
	PATH_ERROR = 1,
	EXEC_ERROR = 1,
	FORK_ERROR = -1,
}	t_errors;

#endif