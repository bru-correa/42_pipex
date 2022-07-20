/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:40:07 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/20 18:06:02 by bcorrea-         ###   ########.fr       */
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

/********** MACROS ***********/
# define CHILD_ID 0
# define INPUT 0
# define OUTPUT 1
# define READ_END 0
# define WRITE_END 1

/********** PROTOTYPES **********/
void	exit_error(char *msg);
void	exec_redir(char *cmd, char **envp);
void	exec_last_cmd(char *cmd, char **envp, int file_out);
void	exec_cmd(char *cmd, char **envp);
char	*get_cmd_path(char *cmd, char **envp);
int		read_input(int argc, char **argv, int *files);
char	**parse_cmd(char *cmd);
int		count_cmd_args(char *cmd);

#endif
