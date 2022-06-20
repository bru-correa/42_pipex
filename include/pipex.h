/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:40:07 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/06/18 17:38:19 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_command
{
	char	*name;
	char	**flags;
}	t_command;

char	**get_path(char **envp);
void	free_path(char **path);
int		run_cmd(t_command cmd, char **path, char **envp);

#endif
