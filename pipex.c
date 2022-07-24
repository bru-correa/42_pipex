/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:37:19 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/24 03:03:56 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_args(int argc);

int	main(int argc, char *argv[], char *envp[])
{
	check_args(argc);
	exec_first_cmd(argv[FIRST_CMD], envp, argv[INFILE]);
	exec_last_cmd(argv[LAST_CMD], envp, argv[OUTFILE]);
	return (0);
}

static void	check_args(int argc)
{
	if (argc != 5)
	{
		ft_printf("ERROR: Invalid arguments\n");
		exit(EXIT_FAILURE);
	}
}
