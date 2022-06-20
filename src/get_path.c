/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:01:16 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/06/20 13:29:18 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path_str(char **envp);

char	**get_path(char **envp)
{
	char	*path_str;
	char	**path;

	path_str = get_path_str(envp);
	if (path_str == NULL)
		return (NULL);
	path = ft_split(path_str, ':');
	free(path_str);
	return (path);
}

static char	*get_path_str(char **envp)
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
