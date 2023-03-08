/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylmac <sylmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:24:09 by sylducam          #+#    #+#             */
/*   Updated: 2023/03/08 23:36:09 by sylmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header_push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		// ft_putstr("Error\n");
		exit(1);
	}
	else if (is_tab_nb(argv) == -1)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	else
		start(argv);
	return (0);
}
