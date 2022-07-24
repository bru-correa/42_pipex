/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:40:07 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/23 22:37:35 by bcorrea-         ###   ########.fr       */
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

/********** PROTOTYPES **********/
void	exit_perror(char *msg, int error_code);
void	exit_invalid_cmd(char **cmd_args);
void	exec_first_cmd(char *cmd, char **envp, char *filename);
void	exec_last_cmd(char *cmd, char **envp, char *filename);
void	exec_redir(char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
int		read_input(int argc);
char	**parse_cmd(char *cmd);
void	handle_heredoc(char *limiter);

#endif
