/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:02:58 by sylducam          #+#    #+#             */
/*   Updated: 2021/08/12 17:39:38 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_libft.h"

void	ft_min_number(unsigned int min_nb)
{
	if (min_nb > 0)
	{
		ft_min_number(min_nb / 10);
		ft_putchar(min_nb % 10 + '0');
	}
}

void	ft_actual_putnbr(int nb)
{
	unsigned int	min_nb;

	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		min_nb = nb;
		ft_min_number(min_nb);
	}
	else if (nb > 0)
	{
		ft_actual_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		ft_putchar(nb + '0');
	else
		ft_actual_putnbr(nb);
}
