/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:16:41 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 20:21:02 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

void	bottom_push(t_data *data)
{
	//back_rankx_a(data, 1);
	while (data->stack_a->content != data->finish)
		reverse_rotate_a(data);
	push_b(data);
}

void	top_push(t_data *data)
{
	//back_rankx_a(data, 1);
	while (data->stack_a->content != data->finish)
		rotate_a(data);
	push_b(data);
}

void	bottom_push_b(t_data *data)
{
	//back_rankx_a(data, 1);
	while (data->stack_b->content != data->finish)
		reverse_rotate_b(data);
	push_a(data);
}

void	top_push_b(t_data *data)
{
	//back_rankx_a(data, 1);
	while (data->stack_b->content != data->finish)
		rotate_b(data);
	push_a(data);
}
