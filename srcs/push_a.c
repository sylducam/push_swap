/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:57:40 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 17:01:19 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

static void	restack_b(t_data *data)
{
	t_stack	*first;
	t_stack	*last;

	first = data->stack_b->next;
	last = data->stack_b->previous;
	first->previous = last;
	last->next = first;
	data->stack_b = first;
}

static void	add_a_rank(t_data *data)
{
	if (data->size_a < 2)
		data->stack_a->rank++;
	else
	{
		while (data->stack_a->rank < data->size_a)
		{
			data->stack_a->rank++;
			data->stack_a = data->stack_a->next;
		}
			data->stack_a->rank++;
	}
	back_rankx_a(data, 2);
}

static void	add_a_elem(t_data *data)
{
	t_stack	*tmp_stack_b;
	t_stack	*tmp_stack_a;

	tmp_stack_b = data->stack_b;
	tmp_stack_a = data->stack_a;
	if (data->size_b > 1)
		restack_b(data);
	add_a_rank(data);
	tmp_stack_b->next = tmp_stack_a;
	tmp_stack_a->previous = tmp_stack_b;
	data->size_a++;
	if (data->size_a > 1)
	{
		while (tmp_stack_a->rank != data->size_a)
			tmp_stack_a = tmp_stack_a->next;
	}
	tmp_stack_a->next = tmp_stack_b;
	tmp_stack_b->previous = tmp_stack_a;
	data->stack_a = tmp_stack_b;
}

void	create_stack_a(t_data *data)
{
	t_stack	*tmp_stack_b;

	tmp_stack_b = data->stack_b;
	data->stack_a = tmp_stack_b;
	restack_b(data);
	data->stack_a->previous = 0;
	data->stack_a->next = 0;
	data->size_a++;
}

void	push_a(t_data *data)
{
	ft_putstr("pa\n");
	if (data->size_a < 1)
		create_stack_a(data);
	else
		add_a_elem(data);
	rerank_b(data);
	data->size_b--;
}
