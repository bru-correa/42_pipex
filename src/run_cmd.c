/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:45:01 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/06/20 14:32:23 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd_path(t_command cmd, char **path);
static char	*add_path_to_name(char *current_path, char *cmd_name);

int	run_cmd(t_command cmd, char **path, char **envp)
{
	if (access(cmd.name, X_OK) != 0)
	{
		cmd.name = get_cmd_path(cmd, path);
		if (cmd.name == NULL)
			return (-1);
	}
	execve(cmd.name, cmd.flags, envp);
	free(cmd.name);
	return (0);
}

static char	*get_cmd_path(t_command cmd, char **path)
{
	char	*cmd_path;
	int		i;

	i = 0;
	cmd_path = NULL;
	while (path[i] != NULL)
	{
		cmd_path = add_path_to_name(path[i], cmd.name);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		else
			ft_reset_str(&cmd_path);
		i++;
	}
	ft_printf("%s: Command not found\n", cmd.name);
	return (cmd_path);
}

static char	*add_path_to_name(char *current_path, char *cmd_name)
{
	char	*full_path;
	char	*path_backslash;

	path_backslash = ft_strjoin(current_path, "/");
	full_path = ft_strjoin(path_backslash, cmd_name);
	free(path_backslash);
	return (full_path);
}
