/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:16:48 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 17:06:45 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

static void free_stack_b(t_data *data)
{
	t_stack *tmp_stack;

	tmp_stack = data->stack_b;
	data->stack_b = data->stack_b->next;
	while (data->size_b)
	{
		free(tmp_stack);
		tmp_stack = NULL;
		tmp_stack = data->stack_b;
		data->stack_b = data->stack_b->next;
		data->size_b--;
	}
}

static void free_stack_a(t_data *data)
{
	t_stack *tmp_stack;

	tmp_stack = data->stack_a;
	data->stack_a = data->stack_a->next;
	while (data->size_a)
	{
		free(tmp_stack);
		tmp_stack = NULL;
		tmp_stack = data->stack_a;
		data->stack_a = data->stack_a->next;
		data->size_a--;
	}
}

void free_stacks(t_data *data)
{
	if (data->size_a)
		free_stack_a(data);
	if (data->size_b)
		free_stack_b(data);
	free(data);
	data = NULL;
	exit(1);
}

void abort_prog(t_data *data)
{
	ft_putstr("Error\n");
	free_stacks(data);
	exit(1);
}