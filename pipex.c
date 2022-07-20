/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:37:19 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/04 19:46:49 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	files[2];
	int	current_arg;

	current_arg = read_input(argc, argv, files);
	while (current_arg < argc - 2)
	{
		exec_redir(argv[current_arg], envp);
		current_arg++;
	}
	exec_last_cmd(argv[current_arg], envp, files[OUTPUT]);
	return (0);
}
