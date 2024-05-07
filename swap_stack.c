/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:43:30 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/08 00:48:43 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_lst_node **stack)
{
	t_stack_lst_node	*nd;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("jj");
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

void	final_steps(t_stack_lst_node **stack, t_stack_lst_node *top_node,
		char nm_stack)
{
	while (*stack != top_node)
	{
		if (nm_stack == 'a')
		{
			if (top_node->before_middle)
			{
				retate(stack);
				write(1, "ra\n", 3);
			}
			else
			{
				reverse_retate(stack);
				write(1, "rra\n", 4);
			}
		}
		else if (nm_stack == 'b')
		{
			if (top_node->before_middle)
			{
				retate(stack);
				write(1, "rb\n", 3);
			}
			else
			{
				reverse_retate(stack);
				write(1, "rrb\n", 4);
			}
		}
	}
}