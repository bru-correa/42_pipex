/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:20:07 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/07/23 23:48:24 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_input(int argc)
{
	if (argc == 5)
		return (2);
	ft_printf("ERROR: Invalid arguments\n");
	exit(EXIT_FAILURE);
	return (-1);
}
