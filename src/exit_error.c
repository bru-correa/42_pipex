/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:05:46 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/23 20:03:52 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmd_args(char **cmd_args);

void	exit_perror(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}

void	exit_invalid_cmd(char **cmd_args)
{
	ft_putstr_fd(cmd_args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_cmd_args(cmd_args);
	exit(127);
}

static void	free_cmd_args(char **cmd_args)
{
	int	i;

	i = 0;
	while (cmd_args[i] != NULL)
	{
		free(cmd_args[i]);
		i++;
	}
	free(cmd_args);
}
