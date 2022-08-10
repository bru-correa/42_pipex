/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:40:07 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/08/09 23:44:32 by bcorrea-         ###   ########.fr       */
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
# define READ_END 0
# define WRITE_END 1
# define ERROR -1

/********** PROTOTYPES **********/

/**
* @brief Print a message describing the meaning of the value of errno, then exit
the program

* @param msg The message before perror
* @param error_code The exit code
*/
void	exit_perror(char *msg, int error_code);

/**
* @brief Print in standard error the command not found, free cmd_args and exit
* with the code 127

* @param cmd_args The command arguments matrix
*/
void	exit_invalid_cmd(char **cmd_args);

/**
 * @brief Open 'filename' and redirect it to standard input. Then fork and exec
 * 'cmd' in the child process.
 *
 * @param cmd The command string to be executed
 * @param envp The environment variables
 * @param filename The name of the file to be opened
 *
*/
void	exec_first_cmd(char *cmd, char **envp, char *filename);

/**
 * @brief Open 'filename' with the 'o_flag' and redirect it to standard output.
 * Then fork and exec 'cmd' in the child process
 *
 * @param cmd The command string to be executed
 * @param envp The environment variables
 * @param filename The name of the file to be opened
 * @param o_flag The flag that will be used when opening 'filename'
*/
void	exec_last_cmd(char *cmd, char **envp, char *filename, int o_flag);

/**
 * @brief Try to find the command using the PATH environment variable, if it
 * finds the command, it will execute it, else it will print the meaning of
 * errno and exit
 *
 * @param cmd The command string to be executed
 * @param envp The environment variables
*/
void	exec_cmd(char *cmd, char **envp);

/**
 * @brief Fork,then redirect the pipe read end to the main processs standard
 * input and redirect the pipe write end to the child process standard output
 *
 * @param cmd The command to be executed
 * @param envp The environment variables
*/
void	exec_redir(char *cmd, char **envp);

/**
 * @brief Try to find the command using the PATH environment variable, if it
 * finds the command, it will return the command absolute path
 *
 * @param cmd The command to be found in the system
 * @param envp The environment variables
 * @return The command absolute path
*/
char	*get_cmd_path(char *cmd, char **envp);

/**
 * @brief Return the index of the first occurence of a non ' ' character, in
 * 'cmd', starting from the 'start' index
 *
 * @param cmd The string to be analyzed
 * @param start The start index
 * @return The index of the first occurence of a non ' ' character
*/
int		skip_spaces(char *cmd, int start);

/**
 * @brief Allocate memory and then split the command string into mutiple
 * substrings, each representing an argument from 'cmd'.
 *
 * @param cmd The command string to be split
 * @return Return the command arguments matrix
 */
char	**parse_cmd(char *cmd);

/**
 * @brief Count how many command arguments the 'cmd' string contains
 *
 * @param cmd The command string
 * @return The number of arguments
 */
int		count_cmd_args(char *cmd);

/**
 * @brief Redirect the pipe write end to standard output
 *
 * @param pipe_fd The opened pipe
 */
void	redir_pipe_to_stdout(int *pipe_fd);

/**
 * @brief Redirect the pipe read end to standard input
 *
 * @param pipe_fd The opened pipe
 */
void	redir_pipe_to_stdin(int *pipe_fd);

/**
 * @brief Redirec the opened file with the flag 'o_flag' to the file
 * descriptor 'fd'
 *
 * @param filename The name of the file to be opened
 * @param o_flag The flag to be used when opening the file
 * @param fd The file descriptor
 */
void	redir_file_to_fd(char *filename, int o_flag, int fd);

/**
 * @brief Create a pipe, store it in 'pipe_f', fork and store the process id in
 * 'pid'
 *
 * @param pipe_fd The variable that will hold the pipe file descriptors
 * @param pid The variable that will hold the process id from fork
 */
void	create_pipe_and_fork(int *pipe_fd, pid_t *pid);

/**
 * @brief Read the command line arguments and check for errors. If everything is
 * correct, it will return the index of the first command in argv
 *
 * @param argc The number of arguments
 * @param argv The arguments from the command line
 * @return The index of the first command in argv
 */
int		read_input(int argc, char **argv);

/**
 * @brief It will keep reading the heredoc until it reaches a line with just the
 * 'limiter'. The output from heredoc will be redirected to standard input
 *
 * @param limiter The limiter that will stop the heredoc from reading the next
 * line
 */
void	handle_heredoc(char *limiter);

#endif
