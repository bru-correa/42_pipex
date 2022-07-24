/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:30:49 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/24 03:25:02 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*get_next_cmd_arg(char *cmd, int *start_index);
static char	*handle_single_quote(char *cmd, int *start_index);

char	**parse_cmd(char *cmd)
{
	char	**cmd_args;
	int		cmd_args_count;
	int		current_arg;
	int		start_index;

	if (cmd == NULL)
		return (NULL);
	cmd_args_count = count_cmd_args(cmd);
	cmd_args = malloc(sizeof(char *) * (cmd_args_count + 1));
	if (cmd_args == NULL)
		return (NULL);
	current_arg = 0;
	start_index = 0;
	while (current_arg < cmd_args_count)
	{
		cmd_args[current_arg] = get_next_cmd_arg(cmd, &start_index);
		current_arg++;
	}
	cmd_args[current_arg] = NULL;
	return (cmd_args);
}

static char	*get_next_cmd_arg(char *cmd, int *start_index)
{
	unsigned int	i;
	char			*cmd_arg;

	*start_index = skip_spaces(cmd, *start_index);
	if (cmd[*start_index] == '\'')
	{
		cmd_arg = handle_single_quote(cmd, start_index);
		return (cmd_arg);
	}
	i = *start_index;
	while (cmd[i] != '\0' && cmd[i] != ' ')
		i++;
	cmd_arg = ft_substr(cmd, *start_index, i - *start_index);
	*start_index = i;
	return (cmd_arg);
}

static char	*handle_single_quote(char *cmd, int *start_index)
{
	int		i;
	char	*cmd_arg;

	*start_index += 1;
	i = *start_index;
	while (cmd[i] != '\0' && cmd[i] != '\'')
		i++;
	cmd_arg = ft_substr(cmd, *start_index, i - *start_index);
	*start_index = i + 1;
	return (cmd_arg);
}
