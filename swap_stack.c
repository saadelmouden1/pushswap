/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:43:30 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/09 01:51:33 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_lst_node **stack)
{
	t_stack_lst_node	*nd;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	nd = *stack;
	(*stack) = (*stack)->next;
	nd->next = (*stack)->next;
	(*stack)->next = nd;
	(*stack)->prev = NULL;
	nd->prev = (*stack);
	if (nd->next)
		nd->next->prev = nd;
}

static void	retate_a(t_stack_lst_node **stack)
{
	retate(stack);
	write(1, "ra\n", 3);
}

static void	retate_b(t_stack_lst_node **stack)
{
	retate(stack);
	write(1, "rb\n", 3);
}

void	final_steps(t_stack_lst_node **stack, t_stack_lst_node *top_node,
		char nm_stack)
{
	while (*stack != top_node)
	{
		if (nm_stack == 'a')
		{
			if (top_node->before_middle)
				retate_a(stack);
			else
			{
				reverse_retate(stack);
				write(1, "rra\n", 4);
			}
		}
		else if (nm_stack == 'b')
		{
			if (top_node->before_middle)
				retate_b(stack);
			else
			{
				reverse_retate(stack);
				write(1, "rrb\n", 4);
			}
		}
	}
}

void	refresh_nodes(t_stack_lst_node *a, t_stack_lst_node *b)
{
	get_update_pos(a);
	get_update_pos(b);
	get_place_to_move(a, b);
	set_moves(a, b);
	get_small_num_moves(b);
}
