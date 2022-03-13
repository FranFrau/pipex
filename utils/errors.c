/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:25:39 by ffrau             #+#    #+#             */
/*   Updated: 2022/03/13 12:42:40 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_exit_error(char *s, int err)
{
	perror(s);
	exit(err);
}

void	print_error(char *s, int err)
{
	ft_putstr_fd(s, 2);
	exit(err);
}
