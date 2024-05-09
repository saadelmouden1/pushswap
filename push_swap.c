/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:43:17 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/09 00:36:24 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	retate_a_b(t_stack_lst_node **a, t_stack_lst_node **b)
{
	retate(a);
	retate(b);
	write(1, "rr\n", 3);
}

static void	reverse_retate_a_b(t_stack_lst_node **a, t_stack_lst_node **b)
{
	reverse_retate(a);
	reverse_retate(b);
	write(1, "rrr\n", 4);
}

void	move_nodes(t_stack_lst_node **a, t_stack_lst_node **b)
{
	t_stack_lst_node	*node_to_move;

	node_to_move = get_smallest_moves_nd(*b);
	if (node_to_move->before_middle && node_to_move->place_node->before_middle)
	{
		while (*a != node_to_move->place_node && *b != node_to_move)
			retate_a_b(a, b);
		get_update_pos(*a);
		get_update_pos(*b);
	}
	else if (!(node_to_move->before_middle)
		&& !(node_to_move->place_node->before_middle))
	{
		while (*a != node_to_move->place_node && *b != node_to_move)
			reverse_retate_a_b(a, b);
		get_update_pos(*a);
		get_update_pos(*b);
	}
	final_steps(b, node_to_move, 'b');
	final_steps(a, node_to_move->place_node, 'a');
	push_stack(a, b);
	write(1, "pa\n", 3);
}

static void	loop_stack_retete(t_stack_lst_node **stack_a,
		t_stack_lst_node *small_node)
{
	while (*stack_a != small_node)
	{
		retate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	push_swap(t_stack_lst_node **stack_a, t_stack_lst_node **stack_b)
{
	int					i;
	t_stack_lst_node	*small_node;

	i = get_list_size(*stack_a);
	while (i > 3)
	{
		push_stack(stack_b, stack_a);
		write(1, "pb\n", 3);
		i--;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		refresh_nodes(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	get_update_pos(*stack_a);
	small_node = get_small_number(*stack_a);
	if (small_node->before_middle)
		loop_stack_retete(stack_a, small_node);
	else
		loop_stack_rev_retate(stack_a, small_node);
}
