/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:17:08 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/06 14:41:07 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*add_path_prefix(char *cmd, char **path);
static void	free_path(char **path);
static char	**get_path(char **envp);
static char	*get_path_line(char **envp);

//TODO: Change cmd name
char	*get_cmd_path(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**path;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	path = get_path(envp);
	cmd_path = add_path_prefix(cmd, path);
	free_path(path);
	if (cmd_path == NULL)
		exit_error("ERROR: Command not found\n");
	return (cmd_path);
}

static char	*add_path_prefix(char *cmd, char **path)
{
	char	*cmd_path;
	char	*current_path;
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		current_path = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(current_path, cmd);
		free(current_path);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

static void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i] == NULL)
	{
		free(path[i]);
		i++;
	}
	free(path);
}

static char	**get_path(char **envp)
{
	char	*path_str;
	char	**path;

	path_str = get_path_line(envp);
	if (path_str == NULL)
		exit_error("ERROR: Path not found!\n");
	path = ft_split(path_str, ':');
	free(path_str);
	return (path);
}

static char	*get_path_line(char **envp)
{
	int		i;
	char	*path_str;

	i = 0;
	path_str = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_str = ft_strdup(&envp[i][5]);
			break ;
		}
		i++;
	}
	return (path_str);
}