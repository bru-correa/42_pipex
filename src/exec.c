/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:03:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/08/09 22:42:31 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_first_cmd(char *cmd, char **envp, char *filename)
{
	pid_t	pid;
	int		pipe_fd[2];

	create_pipe_and_fork(pipe_fd, &pid);
	if (pid == CHILD_ID)
	{
		redir_file_to_fd(filename, O_RDONLY, STDIN_FILENO);
		redir_pipe_to_stdout(pipe_fd);
		exec_cmd(cmd, envp);
	}
	redir_pipe_to_stdin(pipe_fd);
	waitpid(pid, NULL, WNOHANG);
	return ;
}

void	exec_redir(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	create_pipe_and_fork(pipe_fd, &pid);
	if (pid == CHILD_ID)
	{
		redir_pipe_to_stdout(pipe_fd);
		exec_cmd(cmd, envp);
	}
	redir_pipe_to_stdin(pipe_fd);
	waitpid(pid, NULL, WNOHANG);
	return ;
}

void	exec_last_cmd(char *cmd, char **envp, char *filename, int o_flag)
{
	redir_file_to_fd(filename, o_flag, STDOUT_FILENO);
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
