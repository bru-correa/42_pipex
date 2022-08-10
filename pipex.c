/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:37:19 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/08/09 22:46:36 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_input(int argc, char **argv, char **envp, int *have_heredoc);

int	main(int argc, char *argv[], char *envp[])
{
	int	current_arg;
	int	have_heredoc;

	current_arg = check_input(argc, argv, envp, &have_heredoc);
	while (current_arg < argc - 2)
	{
		exec_redir(argv[current_arg], envp);
		current_arg++;
	}
	if (have_heredoc == TRUE)
		exec_last_cmd(argv[current_arg], envp, argv[argc - 1],
			O_WRONLY | O_APPEND | O_CREAT);
	else
		exec_last_cmd(argv[current_arg], envp, argv[argc - 1],
			O_WRONLY | O_TRUNC | O_CREAT);
	return (0);
}

static int	check_input(int argc, char **argv, char **envp, int *have_heredoc)
{
	int	current_arg;

	current_arg = read_input(argc, argv);
	if (current_arg == 2)
	{
		exec_first_cmd(argv[current_arg], envp, argv[1]);
		current_arg++;
		*have_heredoc = FALSE;
	}
	else
		*have_heredoc = TRUE;
	return (current_arg);
}
