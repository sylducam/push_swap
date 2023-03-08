/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tab_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:37:26 by sylducam          #+#    #+#             */
/*   Updated: 2021/08/13 18:16:08 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_libft.h"

int	is_tab_nb(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j++]) == 0)
				return (-1);
		}
		if (i == INT_MAX && tab[2147483648] != 0)
			return (-1);
		i++;
	}
	return (0);
}
