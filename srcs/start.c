/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:17:28 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 18:02:43 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

static int already_sorted(t_data *data)
{
	int sorted;

	sorted = 1;
	while (data->stack_a->rank < data->size_a)
	{
		if (data->stack_a->content != sorted)
			return (-1);
		data->stack_a = data->stack_a->next;
		sorted++;
	}
	if (data->stack_a->content != sorted)
		return (-1);
	return (0);
}

void	start(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(*data));
	ft_bzero(data, sizeof(*data));
	while (argv[data->count + 1])
		data->count++;
	store_stacks(data, argv);
	transform_numbers(data);
	if (already_sorted(data) == 0)
		free_stacks(data);
	sort(data);
	// display_stack_a(data);
	// display_stack_b(data);
	free_stacks(data);
}