/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:29:42 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 17:01:44 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

static void	restack_a(t_data *data)
{
	t_stack	*first;
	t_stack	*last;

	first = data->stack_a->next;
	last = data->stack_a->previous;
	first->previous = last;
	last->next = first;
	data->stack_a = first;
}

static void	add_b_rank(t_data *data)
{
	if (data->size_b < 2)
		data->stack_b->rank++;
	else
	{
		while (data->stack_b->rank < data->size_b)
		{
			data->stack_b->rank++;
			data->stack_b = data->stack_b->next;
		}
			data->stack_b->rank++;
	}
	back_rankx_b(data, 2);
}

static void	add_b_elem(t_data *data)
{
	t_stack	*tmp_stack_a;
	t_stack	*tmp_stack_b;

	tmp_stack_a = data->stack_a;
	tmp_stack_b = data->stack_b;
	if (data->size_a > 1)
		restack_a(data);
	add_b_rank(data);
	tmp_stack_a->next = tmp_stack_b;
	tmp_stack_b->previous = tmp_stack_a;
	data->size_b++;
	if (data->size_b > 1)
	{
		while (tmp_stack_b->rank != data->size_b)
			tmp_stack_b = tmp_stack_b->next;
	}
	tmp_stack_b->next = tmp_stack_a;
	tmp_stack_a->previous = tmp_stack_b;
	data->stack_b = tmp_stack_a;
}

void	create_stack_b(t_data *data)
{
	t_stack	*tmp_stack_a;

	tmp_stack_a = data->stack_a;
	data->stack_b = tmp_stack_a;
	restack_a(data);
	data->stack_b->previous = 0;
	data->stack_b->next = 0;
	data->size_b++;
}

void	push_b(t_data *data)
{
	ft_putstr("pb\n");
	if (!data->stack_b)
		create_stack_b(data);
	else
		add_b_elem(data);
	rerank_a(data);
	data->size_a--;
}
