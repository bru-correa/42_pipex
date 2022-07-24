/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:40:07 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/24 04:48:29 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/********** INCLUDE **********/
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

/********** MACROS ***********/
# define CHILD_ID 0
# define READ_END 0
# define WRITE_END 1
# define ERROR -1

/********** PROTOTYPES **********/
void	exit_perror(char *msg, int error_code);
void	exit_invalid_cmd(char **cmd_args);
void	exec_first_cmd(char *cmd, char **envp, char *filename);
void	exec_last_cmd(char *cmd, char **envp, char *filename, int o_flag);
void	exec_cmd(char *cmd, char **envp);
void	exec_redir(char *cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
int		skip_spaces(char *cmd, int start);
char	**parse_cmd(char *cmd);
int		count_cmd_args(char *cmd);
void	redir_pipe_to_stdout(int *pipe_fd);
void	redir_pipe_to_stdin(int *pipe_fd);
void	redir_file_to_fd(char *filename, int o_flag, int fd);
void	create_pipe_and_fork(int *pipe_fd, pid_t *pid);
int		read_input(int argc, char **argv);
void	handle_heredoc(char *limiter);

#endif
