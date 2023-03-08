/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:57:41 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/01 17:01:43 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

void	rotate_b(t_data *data)
{
	ft_putstr("rb\n");
	back_rankx_a(data, 1);
	data->stack_b = data->stack_b->next;
	while (data->stack_b->rank != 1)
	{
		data->stack_b->rank--;
		data->stack_b = data->stack_b->next;
	}
	data->stack_b->rank = data->size_b;
	back_rankx_b(data, 1);
}

void	rotate_a(t_data *data)
{
	ft_putstr("ra\n");
	back_rankx_a(data, 1);
	data->stack_a = data->stack_a->next;
	while (data->stack_a->rank != 1)
	{
		data->stack_a->rank--;
		data->stack_a = data->stack_a->next;
	}
	data->stack_a->rank = data->size_a;
	back_rankx_a(data, 1);
}

void	rotate_both(t_data *data)
{
	ft_putstr("rr\n");
	back_rankx_a(data, 1);
	data->stack_a = data->stack_a->next;
	while (data->stack_a->rank != 1)
	{
		data->stack_a->rank--;
		data->stack_a = data->stack_a->next;
	}
	data->stack_a->rank = data->size_a;
	back_rankx_a(data, 1);
	data->stack_b = data->stack_b->next;
	while (data->stack_b->rank != 1)
	{
		data->stack_b->rank--;
		data->stack_b = data->stack_b->next;
	}
	data->stack_b->rank = data->size_b;
	back_rankx_b(data, 1);

}