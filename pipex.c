/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:37:19 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/23 22:37:24 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	current_arg;
	// int	file_out;

	current_arg = read_input(argc);
	// file_out = open(argv[argc - 1], O_RDWR | O_CREAT);
	// if (file_out < 0)
	// 	exit_perror(argv[argc - 1], 1);
	exec_first_cmd(argv[current_arg], envp, argv[1]);
	current_arg++;
	// while (current_arg < argc - 2)
	// {
	// 	exec_redir(argv[current_arg], envp);
	// 	current_arg++;
	// }
	exec_last_cmd(argv[current_arg], envp, argv[current_arg + 1]);
	return (0);
}
