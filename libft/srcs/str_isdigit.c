/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_isdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:30:41 by sylducam          #+#    #+#             */
/*   Updated: 2021/05/17 17:22:35 by sylducam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_libft.h"

int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (-1);
	while (str[i])
	{
		if (!(str[i] >= '0') && !(str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}
