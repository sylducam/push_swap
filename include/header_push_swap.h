/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_push_swap.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylducam <sylducam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:27:57 by sylducam          #+#    #+#             */
/*   Updated: 2021/10/07 20:21:45 by sylducam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PUSH_SWAP_H
# define HEADER_PUSH_SWAP_H

# include "../libft/includes/header_libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
    int     count;
    int     size_a;
    int     size_b;
    int     min;
    int     max;
    int     aim_min;
    int     aim_max;
    int     to_turn;
    int     cresc;
    int     numbers_turned;
    int     divisor;
    int     chunk;
    int     finish;
	int		current_block;
    t_stack *stack_a;
    t_stack *stack_b;
}   t_data;


void	abort_prog(t_data *data);
void	free_stacks(t_data *data);
void	start(char **argv);
void	store_stacks(t_data *data, char **argv);
void	transform_numbers(t_data *data);
void    push_a(t_data *data);
void    push_b(t_data *data);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_both(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_both(t_data *data);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_both(t_data *data);
void	create_stack_b(t_data *data);
void	loop_stack_a(t_data *data);
void	loop_stack_b(t_data *data);
void	relink_a(t_data *data);
void	relink_b(t_data *data);
void	reloop_stack_a(t_data *data);
void	reloop_stack_b(t_data *data);
void	back_rankx_a(t_data *data, int x);
void	back_rankx_b(t_data *data, int x);
void	rerank_a(t_data *data);
void	rerank_b(t_data *data);
void	sort(t_data *data);
void	seek_min_max(t_data *data);
void	top_push(t_data *data);
void	bottom_push(t_data *data);
void	top_push_b(t_data *data);
void	bottom_push_b(t_data *data);
void    display_stack_a(t_data *data); // a virer
void    display_stack_b(t_data *data); // a virer

#endif
