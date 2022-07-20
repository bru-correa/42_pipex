/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:20:07 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/06/30 17:05:33 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_files(int argc, char **argv, int *files);

/* TODO Handle here_doc */
int	read_input(int argc, char **argv, int *files)
{
	if (argc >= 6 && ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		files[OUTPUT] = open(argv[argc - 1], O_RDWR);
		if (files[OUTPUT] == -1)
			exit_error("ERROR: Could not open output file\n");
		return (3);
	}
	else if (argc >= 5)
	{
		open_files(argc, argv, files);
		dup2(files[INPUT], STDIN_FILENO);
		close(files[INPUT]);
		return (2);
	}
	exit_error("ERROR: Invalid arguments\n");
	return (-1);
}

/* TODO Create a modular function than open either of the files
*  And receive flags as parameter */
static void	open_files(int argc, char **argv, int *files)
{
	files[INPUT] = open(argv[1], O_RDONLY);
	if (files[INPUT] == -1)
		exit_error("ERROR: Could not open input file\n");
	files[OUTPUT] = open(argv[argc - 1], O_RDWR);
	if (files[OUTPUT] == -1)
		exit_error("ERROR: Could not open output file\n");
}
