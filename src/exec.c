/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:03:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/22 16:59:54 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_redir(char *cmd, char **envp)
{
	int	pipe_fd[2];
	int	pid;

	if (pipe(pipe_fd) < 0)
		exit_perror("ERROR: Could not open pipe\n", 1);
	pid = fork();
	if (pid < 0)
		exit_perror("ERROR: Failed to handle fork\n", 1);
	if (pid > 0)
	{
		close(pipe_fd[WRITE_END]);
		dup2(pipe_fd[READ_END], STDIN_FILENO);
		close(pipe_fd[READ_END]);
		waitpid(pid, NULL, 0);
		return ;
	}
	close(pipe_fd[READ_END]);
	dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
	close(pipe_fd[WRITE_END]);
	exec_cmd(cmd, envp);
}

void	exec_last_cmd(char *cmd, char **envp, int file_out)
{
	dup2(file_out, STDOUT_FILENO);
	close(file_out);
	exec_cmd(cmd, envp);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;
	int		error_code;

	cmd_args = parse_cmd(cmd);
	if (cmd_args == NULL)
		exit_perror("ERROR: Could not get cmd args\n", 1);
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (cmd_path == NULL)
		exit_invalid_cmd(cmd_args);
	execve(cmd_path, cmd_args, envp);
	error_code = errno;
	exit_perror(cmd_path, error_code);
}
