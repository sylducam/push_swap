/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:23:21 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 16:19:14 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

static void	create_stack_a(t_data *data, char **argv)
{
	data->stack_a = malloc(sizeof(*data->stack_a));
	if (data->stack_a == NULL)
		abort_prog(data);
	data->size_a++;
	data->stack_a->rank = 1;
	data->stack_a->content = ft_atoll(argv[1]);
	data->stack_a->turned = false;
	if (data->stack_a->content < INT_MIN || data->stack_a->content > INT_MAX)
		abort_prog(data);
	data->stack_a->previous = 0;
	data->stack_a->next = 0;
}

void	store_stacks(t_data *data, char **argv)
{
	t_stack	*tmp_stack;
	int		i;

	i = 2;
	create_stack_a(data, argv);
	tmp_stack = data->stack_a;
	while (argv[i])
	{
		data->stack_a = malloc(sizeof(*data->stack_a));
		if (data->stack_a == NULL)
			abort_prog(data);
		data->size_a++;
		tmp_stack->next = data->stack_a;
		data->stack_a->rank = i;
		data->stack_a->content = ft_atoll(argv[i]);
		data->stack_a->turned = false;
		if (data->stack_a->content < INT_MIN
			|| data->stack_a->content > INT_MAX)
			abort_prog(data);
		data->stack_a->previous = tmp_stack;
		data->stack_a->next = 0;
		tmp_stack = data->stack_a;
		i++;
	}
	back_rankx_a(data, 1);
	loop_stack_a(data);
}
