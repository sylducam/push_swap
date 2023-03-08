/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:17:10 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/01 17:01:43 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

static void	turn_number(t_data *data)
{
	data->stack_a->content = data->cresc;
	data->stack_a->turned = true;
	data->numbers_turned++;
	data->cresc++;
}

static void goto_nbtoturn(t_data *data)
{
	while (data->stack_a->rank != data->to_turn)
		data->stack_a = data->stack_a->next;
}

static void seek_min(t_data *data)
{
	if (data->stack_a->turned == false && data->stack_a->content < data->min)
	{
		data->min = data->stack_a->content;
		data->to_turn = data->stack_a->rank;
	}
	data->stack_a = data->stack_a->next;
}

void transform_numbers(t_data *data)
{
	int finish;

	data->cresc = 1;
	while (data->numbers_turned < data->count)
	{
		while (data->stack_a->turned == true)
			data->stack_a = data->stack_a->next;
		data->min = data->stack_a->content;
		data->to_turn = data->stack_a->rank;
		finish = data->size_a;
		while (finish)
		{
			seek_min(data);
			finish--;
		}
		if (data->stack_a->rank != data->to_turn)
			goto_nbtoturn(data);
		turn_number(data);
		back_rankx_a(data, 1);
	}
}
