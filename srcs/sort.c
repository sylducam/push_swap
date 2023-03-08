/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:21:56 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 20:31:02 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

static void seek_nb_a(t_data *data)
{
	t_stack *tmp_stack;

	tmp_stack = data->stack_a;
	// dprintf(1, "data->finish = %d\n", data->finish);
	while (data->stack_a->content != data->finish)
		data->stack_a = data->stack_a->next;
	if (data->stack_a->rank <= data->count / 2)
	{
		data->stack_a = tmp_stack;
		top_push(data);
	}
	else
	{
		data->stack_a = tmp_stack;
		bottom_push(data);
	}
}

static void seek_nb_b(t_data *data)
{
	t_stack *tmp_stack;

	tmp_stack = data->stack_b;
	// dprintf(1, "data->finish = %d\n", data->finish);
	while (data->stack_b->content != data->finish)
		data->stack_b = data->stack_b->next;
	if (data->stack_b->rank <= data->count / 2)
	{
		data->stack_b = tmp_stack;
		top_push_b(data);
	}
	else
	{
		data->stack_b = tmp_stack;
		bottom_push_b(data);
	}
}

// static void	seek_nb(t_data *data)
// {

// }

static void seek_nb(t_data *data)
{
	t_stack *tmp_stack;
	int ra;
	int rra;
	int min;
	int max;
	int row;

	if (data->chunk > data->size_a)
		row = data->chunk - data->size_a;
	else
		row = 0;
	while (row++ < data->chunk)
	{
		tmp_stack = data->stack_a;
		ra = 0;
		rra = 1;
		min = data->chunk * data->current_block - data->chunk + 1;
		max = data->chunk * data->current_block;
		// dprintf(1, "\n///// BLOCK NUMBER %d min = %d max = %d//////\n", data->current_block, min, max); // del
		// dprintf(1, "a->content = %d\n", data->stack_a->content); // del
		// display_stack_a(data);
		while (data->stack_a->content < min || data->stack_a->content > max)
		{
			// dprintf(1, "a->content = %lld\n", data->stack_a->content); // del
			data->stack_a = data->stack_a->next;
			ra++;
		}
		data->finish = data->stack_a->content;
		data->stack_a = tmp_stack->previous;
		while (data->stack_a->content < min || data->stack_a->content > max)
		{
			// dprintf(1, "a->content = %lld\n", data->stack_a->content); // del
			data->stack_a = data->stack_a->previous;
			rra++;
		}
		// dprintf(1, "ra = %d rra = %d\n", ra, rra); // del
		if (ra <= rra)
		{
			data->stack_a = tmp_stack;
			top_push(data);
		}
		else
		{
			data->finish = data->stack_a->content;
			data->stack_a = tmp_stack;
			bottom_push(data);
		}
	}
}

static void sort_three(t_data *data)
{
	seek_min_max(data);
	if (data->aim_min == 2 && data->aim_max == 3)
		swap_a(data);
	if (data->aim_min == 3 && data->aim_max == 1)
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
	if (data->aim_min == 3 && data->aim_max == 2)
		reverse_rotate_a(data);
	if (data->aim_min == 1 && data->aim_max == 2)
	{
		swap_a(data);
		rotate_a(data);
	}
	if (data->aim_min == 2 && data->aim_max == 1)
		rotate_a(data);
}

static void beneath_six(t_data *data)
{
	if (data->count == 4)
		seek_nb_a(data);
	if (data->count == 5)
	{
		seek_nb_a(data);
		data->finish++;
		seek_nb_a(data);
	}
	sort_three(data);
	if (data->count == 4)
		push_a(data);
	if (data->count == 5)
	{
		push_a(data);
		push_a(data);
	}
}

/*
static void above_five(t_data *data)
{
	int row;

	while (data->divisor > 0 || data->finish <= data->count)
	{
		if (data->divisor)
			row = data->chunk;
		else
			row = data->count - data->finish;
		while (row && data->size_a)
		{
			seek_nb(data);
			data->finish++;
			row--;
		}
		data->divisor--;
	}
	back_rankx_b(data, 1);
	data->finish = 0;
	while (data->finish < data->count)
	{
		push_a(data);
		data->finish++;
	}
}
*/
static void above_five(t_data *data)
{
	// display_stack_a(data); // del
	while (data->current_block++ < data->divisor || data->size_a)
		seek_nb(data);
	// display_stack_b(data);
	back_rankx_b(data, 1);
	data->finish = data->size_b;
	while (data->finish > 0)
	{
		seek_nb_b(data);
		data->finish--;
	}
}

void sort(t_data *data)
{
	back_rankx_a(data, 1);
	data->finish = 1;
	if (data->count <= 5)
		data->divisor = 0;
	else if (data->count < 100)
		data->divisor = 5;
	// else if (data->count < 350)
		// data->divisor = 20;
	// else if (data->count < 400)
		// data->divisor = 30;
	else if (data->count < 500)
		data->divisor = 11;
	else
		data->divisor = 13;
	if (data->divisor)
	{
		data->chunk = data->count / data->divisor;
	// dprintf(1, "data->divisor = %d | data->chunk = %d\n", data->divisor, data->chunk); // del
		above_five(data);
	}
	else
		beneath_six(data);
}

	// if (data->count <= 5)
	// 	data->divisor = 0;
	// else if (data->count < 100)
	// 	data->divisor = 10;
	// else if (data->count < 350)
	// 	data->divisor = 20;
	// else if (data->count < 400)
	// 	data->divisor = 30;
	// else if (data->count < 500)
	// 	data->divisor = 40;
	// else
	// 	data->divisor = 50;
