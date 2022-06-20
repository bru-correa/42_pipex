/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:37:19 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/06/20 13:36:03 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char		**path;
	__pid_t		pid1;
	t_command	cmd;

	if (argc == 1)
		return (1);
	path = get_path(envp);
	if (path == NULL)
	{
		ft_printf("ERROR: Path Not Found!\n");
		return (1);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		cmd.name = argv[1];
		cmd.flags = &argv[2];
		run_cmd(cmd, path, envp);
		free_path(path);
	}
	if (pid1 != 0)
	{
		free_path(path);
	}
	return (0);
}
