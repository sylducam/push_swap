/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:13:38 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/01 17:01:43 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

void	reverse_rotate_b(t_data *data)
{
	ft_putstr("rrb\n");
	while(data->stack_b->rank != data->size_b)
	{
		data->stack_b->rank++;
		data->stack_b = data->stack_b->next;
	}
	data->stack_b->rank = 1;
	back_rankx_b(data, 1);
}

void	reverse_rotate_a(t_data *data)
{
	ft_putstr("rra\n");
	while(data->stack_a->rank != data->size_a)
	{
		data->stack_a->rank++;
		data->stack_a = data->stack_a->next;
	}
	data->stack_a->rank = 1;
	back_rankx_a(data, 1);
}

void	reverse_rotate_both(t_data *data)
{
	ft_putstr("rrr\n");
	while(data->stack_a->rank != data->size_a)
	{
		data->stack_a->rank++;
		data->stack_a = data->stack_a->next;
	}
	data->stack_a->rank = 1;
	back_rankx_a(data, 1);
	while(data->stack_b->rank != data->size_b)
	{
		data->stack_b->rank++;
		data->stack_b = data->stack_b->next;
	}
	data->stack_b->rank = 1;
	back_rankx_b(data, 1);
}
