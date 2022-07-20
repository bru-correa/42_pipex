/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:30:49 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/20 20:53:36 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	skip_spaces(char *cmd, int start);
static char	*get_next_cmd_arg(char *cmd, int *start_index);
static void	check_for_single_quote(char c, int *single_quote_mode);
static int	count_cmd_args(char *cmd);

char	**parse_cmd(char *cmd)
{
	char	**cmd_args;
	int		cmd_args_count;
	int		current_arg;
	int		cmd_index;

	if (cmd == NULL)
		return (NULL);
	cmd_args_count = count_cmd_args(cmd);
	cmd_args = malloc(sizeof(char *) * cmd_args_count + 1);
	if (cmd_args == NULL)
		return (NULL);
	current_arg = 0;
	cmd_index = 0;
	while (current_arg < cmd_args_count)
	{
		cmd_args[current_arg] = get_next_cmd_arg(cmd, &cmd_index);
		current_arg++;
	}
	cmd_args[current_arg] = NULL;
	return (cmd_args);
}

static int	count_cmd_args(char *cmd)
{
	int	counter;
	int	i;
	int	quote_mode;

	i = skip_spaces(cmd, 0);
	counter = 1;
	quote_mode = FALSE;
	while (cmd[i] != '\0')
	{
		check_for_single_quote(cmd[i], &quote_mode);
		if (cmd[i] == ' ' && quote_mode == FALSE)
		{
			i = skip_spaces(cmd, i);
			if (cmd[i] != '\0')
				counter++;
			continue ;
		}
		i++;
	}
	return (counter);
}

static void	check_for_single_quote(char c, int *single_quote_mode)
{
	if (c == '\'' && *single_quote_mode == FALSE)
		*single_quote_mode = TRUE;
	else if (c == '\'' && *single_quote_mode == TRUE)
		*single_quote_mode = FALSE;
}

static char	*get_next_cmd_arg(char *cmd, int *start_index)
{
	unsigned int		i;
	char				*cmd_arg;
	int					quote_mode;

	*start_index = skip_spaces(cmd, *start_index);
	i = *start_index;
	quote_mode = FALSE;
	while (cmd[i] != '\0')
	{
		check_for_single_quote(cmd[i], &quote_mode);
		if (cmd[i] == ' ' && quote_mode == FALSE)
		{
			cmd_arg = ft_substr(cmd, *start_index, i - *start_index);
			*start_index = i;
			return (cmd_arg);
		}
		i++;
	}
	cmd_arg = ft_substr(cmd, *start_index, i - *start_index);
	return (cmd_arg);
}

static int	skip_spaces(char *cmd, int start)
{
	int	current;

	current = start;
	while (cmd[current] != '\0' && cmd[current] == ' ')
		current++;
	return (current);
}
