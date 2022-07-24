/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:07:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/24 07:18:08 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	parse_heredoc(char *limiter, int *pipe_fd);

void	handle_heredoc(char *limiter)
{
	int	pipe_fd[2];
	int	pid;

	if (limiter == NULL)
		exit_perror("Error: Invalid Limiter\n", 1);
	create_pipe_and_fork(pipe_fd, &pid);
	if (pid == CHILD_ID)
	{
		parse_heredoc(limiter, pipe_fd);
		return ;
	}
	redir_pipe_to_stdin(pipe_fd);
	waitpid(pid, NULL, 0);
}

// ? Maybe add an extra get_next_line in case of memory leaking
static void	parse_heredoc(char *limiter, int *pipe_fd)
{
	char	*line;
	int		limiter_length;

	close(pipe_fd[READ_END]);
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = ft_get_next_line(STDIN_FILENO);
	limiter_length = ft_strlen(limiter);
	while (line != NULL)
	{
		if (ft_strncmp(line, limiter, limiter_length) == 0
			&& line[limiter_length] == '\n')
			break ;
		ft_putstr_fd(line, pipe_fd[WRITE_END]);
		free(line);
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = ft_get_next_line(STDIN_FILENO);
	}
	free(line);
	close(pipe_fd[WRITE_END]);
	exit(EXIT_SUCCESS);
}
