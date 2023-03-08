/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:59:22 by sylducam          #+#    #+#             */
/*   Updated: 2021/06/30 17:46:42 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_libft.h"

void	*ft_memcpy(void *dst, const void *source, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char *)dst;
	src = (unsigned char *)source;
	i = 0;
	if (!dst && !source)
		return (NULL);
	while (n--)
	{
		dest[i] = src[i];
		i++;
	}
	return (dst);
}
