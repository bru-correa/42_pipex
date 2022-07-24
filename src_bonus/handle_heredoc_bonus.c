/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:07:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/24 03:24:50 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	parse_heredoc(char *limiter, int *pipe_fd);

void	handle_heredoc(char *limiter)
{
	int	pipe_fd[2];
	int	pid;

	if (limiter == NULL)
		exit_perror("Error: Invalid Delimiter\n", 1);
	if (pipe(pipe_fd) == -1)
		exit_perror("ERROR: Could not open pipe\n", 1);
	pid = fork();
	if (pid < 0)
		exit_perror("ERROR: Failed to handle fork\n", 1);
	if (pid > CHILD_ID)
	{
		close(WRITE_END);
		dup2(pipe_fd[READ_END], STDIN_FILENO);
		close(pipe_fd[READ_END]);
		wait(NULL);
		return ;
	}
	parse_heredoc(limiter, pipe_fd);
}

// ? Maybe add an extra get_next_line in case of memory leaking
static void	parse_heredoc(char *limiter, int *pipe_fd)
{
	char	*line;
	char	*limiter_newline;
	int		limiter_length;

	close(pipe_fd[READ_END]);
	line = ft_get_next_line(STDIN_FILENO);
	limiter_newline = ft_strjoin(limiter, "\n");
	limiter_length = ft_strlen(limiter_newline);
	while (line != NULL)
	{
		ft_printf("> ");
		if (ft_strncmp(line, limiter_newline, limiter_length + 1) == 0)
		{
			free(line);
			free(limiter_newline);
			close(pipe_fd[WRITE_END]);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, pipe_fd[WRITE_END]);
		free(line);
		line = ft_get_next_line(STDIN_FILENO);
	}
	free(line);
	free(limiter_newline);
	close(WRITE_END);
}
