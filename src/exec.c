/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:03:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/04 19:45:25 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_redir(char *cmd, char **envp)
{
	int	pipe_fd[2];
	int	pid;

	if (pipe(pipe_fd) < 0)
		exit_error("ERROR: Could not open pipe\n");
	pid = fork();
	if (pid < 0)
		exit_error("ERROR: Failed to handle fork\n");
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

	cmd_args = ft_split(cmd, ' ');
	if (cmd_args == NULL)
		exit_error("ERROR: Could not get cmd args\n");
	cmd_path = get_cmd_path(cmd_args[0], envp);
	execve(cmd_path, cmd_args, envp);
	exit_error("Failed to run cmd\n");
}
