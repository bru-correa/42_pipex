/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:20:07 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/08/09 22:43:35 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_input(int argc, char **argv)
{
	if (argc < 5)
	{
		ft_printf("ERROR: Invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 5 && ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		handle_heredoc(argv[2]);
		return (3);
	}
	else
		return (2);
}
