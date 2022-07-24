/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:37:19 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/24 06:50:22 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// TODO Refactor to check_input return if it has here_doc
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
			O_RDWR | O_APPEND);
	else
		exec_last_cmd(argv[current_arg], envp, argv[argc - 1],
			O_RDWR | O_TRUNC);
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
