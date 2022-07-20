/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:28:21 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/20 20:56:35 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	test_cmd(char *cmd);
static void	print_args(char *cmd);

int	main(void)
{
	test_cmd("cat dog");
	test_cmd("tr x bileza ' X' nice");
	test_cmd("' ' ops");
	test_cmd("tail ' file '");
	test_cmd("");
	test_cmd("   cat   dog '   fish' sparrow");
	test_cmd("Hello    World     ");
	test_cmd("     Hey     you      '    '  ");
	return (0);
}

static	void	test_cmd(char *cmd)
{
	ft_printf("Command: %s\n", cmd);
	print_args(cmd);
	ft_printf("\n");
}

static void	print_args(char *cmd)
{
	char	**cmd_args;

	cmd_args = parse_cmd(cmd);
	if (cmd_args == NULL)
	{
		ft_printf("NULL\n");
		return ;
	}
	ft_printf("| ");
	while (*cmd_args != NULL)
	{
		ft_printf("%s | ", *cmd_args);
		cmd_args++;
	}
	ft_printf("\n");
}
