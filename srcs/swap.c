/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:00:16 by sylducam          #+#    #+#             */
/*   Updated: 2021/09/12 14:50:39 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header_push_swap.h"

void	swap_b(t_data *data)
{
	int	tmp1;
	int	tmp2;

	tmp1 = data->stack_b->content;
	ft_putstr("sb\n");
	data->stack_b = data->stack_b->next;
	tmp2 = data->stack_b->content;
	data->stack_b->content = tmp1;
	data->stack_b = data->stack_b->previous;
	data->stack_b->content = tmp2;
}

void	swap_a(t_data *data)
{
	int	tmp1;
	int	tmp2;

	tmp1 = data->stack_a->content;
	ft_putstr("sa\n");
	data->stack_a = data->stack_a->next;
	tmp2 = data->stack_a->content;
	data->stack_a->content = tmp1;
	data->stack_a = data->stack_a->previous;
	data->stack_a->content = tmp2;
}

void	swap_both(t_data *data)
{

	int	tmp1;
	int	tmp2;

	tmp1 = data->stack_a->content;
	ft_putstr("ss\n");
	data->stack_a = data->stack_a->next;
	tmp2 = data->stack_a->content;
	data->stack_a->content = tmp1;
	data->stack_a = data->stack_a->previous;
	data->stack_a->content = tmp2;
	tmp1 = data->stack_b->content;
	data->stack_b = data->stack_b->next;
	tmp2 = data->stack_b->content;
	data->stack_b->content = tmp1;
	data->stack_b = data->stack_b->previous;
	data->stack_b->content = tmp2;
}