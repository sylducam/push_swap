/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:41:26 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 19:47:58 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

void display_stack_a(t_data *data) // a virer
{
	int i = 0;
	dprintf(1, "stack_a\n");
	dprintf(1, "size_a = %d\n", data->size_a);
	if (data->size_a < 1)
		return;
	else if (data->size_a == 1)
	{
		dprintf(1, "%d - ", data->stack_a->rank);
		dprintf(1, "%lld\n", data->stack_a->content);
	}
	else
		while (i < data->size_a)
		{
			dprintf(1, "%d - ", data->stack_a->rank);
			dprintf(1, "%lld\n", data->stack_a->content);
			data->stack_a = data->stack_a->next;
			i++;
		}
	back_rankx_a(data, 1);
}

void display_stack_b(t_data *data) // a virer
{
	int i = 0;
	dprintf(1, "stack_b\n");
	dprintf(1, "size_b = %d\n", data->size_b);
	if (data->size_b < 1)
		return;
	else if (data->size_b == 1)
	{
		dprintf(1, "%d - ", data->stack_b->rank);
		dprintf(1, "%lld\n", data->stack_b->content);
	}
	else
		while (i < data->size_b)
		{
			dprintf(1, "%d - ", data->stack_b->rank);
			dprintf(1, "%lld\n", data->stack_b->content);
			data->stack_b = data->stack_b->next;
			i++;
		}
	back_rankx_b(data, 1);
}

void back_rankx_a(t_data *data, int x)
{
	if (!data->stack_a || data->size_a < 2)
		return ;
	while (data->stack_a->rank != x)
		data->stack_a = data->stack_a->previous;
}

void back_rankx_b(t_data *data, int x)
{
	if (!data->stack_b || data->size_b < 2)
		return ;
	while (data->stack_b->rank != x)
		data->stack_b = data->stack_b->previous;
}

void loop_stack_a(t_data *data)
{
	t_stack *tmp_stack;

	tmp_stack = data->stack_a;
	while (tmp_stack->next)
		tmp_stack = tmp_stack->next;
	data->stack_a->previous = tmp_stack;
	tmp_stack->next = data->stack_a;
}

void rerank_a(t_data *data)
{
	int newrank;

	newrank = 1;
	while (newrank < data->size_a)
	{
		data->stack_a->rank = newrank;
		data->stack_a = data->stack_a->next;
		newrank++;
	}
}

void rerank_b(t_data *data)
{
	int newrank;

	newrank = 1;
	while (newrank < data->size_b)
	{
		data->stack_b->rank = newrank;
		data->stack_b = data->stack_b->next;
		newrank++;
	}
}
