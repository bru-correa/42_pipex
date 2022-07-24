/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:34:58 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/24 01:43:39 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_for_single_quote(char c, int *single_quote_mode);

int	count_cmd_args(char *cmd)
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

int	skip_spaces(char *cmd, int start)
{
	int	current;

	current = start;
	while (cmd[current] != '\0' && cmd[current] == ' ')
		current++;
	return (current);
}

static void	check_for_single_quote(char c, int *single_quote_mode)
{
	if (c == '\'' && *single_quote_mode == FALSE)
		*single_quote_mode = TRUE;
	else if (c == '\'' && *single_quote_mode == TRUE)
		*single_quote_mode = FALSE;
}
