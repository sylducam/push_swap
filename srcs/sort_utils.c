/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:57:42 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 16:58:11 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

void seek_min_max(t_data *data)
{
	int two_times;

	two_times = 2;
	data->min = data->stack_a->content;
	data->aim_min = data->stack_a->rank;
	data->max = data->stack_a->content;
	data->aim_max = data->stack_a->rank;
	data->stack_a = data->stack_a->next;
	while (two_times)
	{
		if (data->stack_a->content < data->min)
		{
			data->min = data->stack_a->content;
			data->aim_min = data->stack_a->rank;
		}
		if (data->stack_a->content > data->max)
		{
			data->max = data->stack_a->content;
			data->aim_max = data->stack_a->rank;
		}
		data->stack_a = data->stack_a->next;
		two_times--;
	}
}