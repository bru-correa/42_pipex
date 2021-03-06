/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:28:21 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/21 19:24:41 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static void	test_cmd(char *cmd);
// static void	print_args(char *cmd);
static void	test_limiter(char *limiter);

int	main(void)
{
	test_limiter("END");
	return (0);
}

static void	test_limiter(char *limiter)
{
	char	*line;
	char	*limiter_newline;
	int		limiter_length;

	line = ft_get_next_line(STDIN_FILENO);
	limiter_newline = ft_strjoin(limiter, "\n");
	limiter_length = ft_strlen(limiter_newline);
	ft_printf("Limiter: %s\n", limiter_newline);
	while (line != NULL)
	{
		ft_printf("%d\n",
			ft_strncmp(line, limiter_newline, limiter_length + 1));
		if (ft_strncmp(line, limiter_newline, limiter_length + 1) == 0)
		{
			free(line);
			free(limiter_newline);
			ft_printf("SUCCESS!\n");
			exit(EXIT_SUCCESS);
		}
		free(line);
		line = ft_get_next_line(STDIN_FILENO);
	}
	free(limiter_newline);
	free(line);
}

// static	void	test_cmd(char *cmd)
// {
// 	ft_printf("Command: %s\n", cmd);
// 	print_args(cmd);
// 	ft_printf("\n");
// }

// static void	print_args(char *cmd)
// {
// 	char	**cmd_args;

// 	cmd_args = parse_cmd(cmd);
// 	if (cmd_args == NULL)
// 	{
// 		ft_printf("NULL\n");
// 		return ;
// 	}
// 	ft_printf("| ");
// 	while (*cmd_args != NULL)
// 	{
// 		ft_printf("%s | ", *cmd_args);
// 		cmd_args++;
// 	}
// 	ft_printf("\n");
// }
