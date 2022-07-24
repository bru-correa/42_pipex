/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:40:07 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/24 02:55:43 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
# define INPUT 0
# define OUTPUT 1
# define READ_END 0
# define WRITE_END 1
# define ERROR -1
# define FIRST_CMD 2
# define LAST_CMD 3
# define INFILE 1
# define OUTFILE 4

/********** PROTOTYPES **********/
void	exit_perror(char *msg, int error_code);
void	exit_invalid_cmd(char **cmd_args);
void	exec_first_cmd(char *cmd, char **envp, char *filename);
void	exec_last_cmd(char *cmd, char **envp, char *filename);
void	exec_redir(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
int		skip_spaces(char *cmd, int start);
char	**parse_cmd(char *cmd);
int		count_cmd_args(char *cmd);
void	redir_pipe_to_stdout(int *pipe_fd);
void	redir_pipe_to_stdin(int *pipe_fd);
void	redir_file_to_fd(char *filename, int o_flag, int fd);
void	create_pipe_and_fork(int *pipe_fd, pid_t *pid);

#endif
