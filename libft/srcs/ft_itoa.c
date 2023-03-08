/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylmac <sylmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:56:47 by sylducam          #+#    #+#             */
/*   Updated: 2023/03/08 23:32:05 by sylmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_libft.h"

static int	size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*fill(unsigned int n, char *str, int size)
{
	str[size] = '\0';
	while (--size + 1)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nb;

	if (n < 0)
	{
		len = size(n) + 1;
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		nb = n * -1;
		fill(nb, str, len);
		str[0] = '-';
	}
	else
	{
		len = size(n);
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		fill(n, str, len);
	}
	return (str);
}
