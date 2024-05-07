/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:43:23 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/07 03:37:50 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retate(t_stack_lst_node **stack)
{
	t_stack_lst_node	*last_node_satck;

	if (stack == NULL || *stack == NULL)
	{
		return ;
	}
	last_node_satck = find_last_node(*stack);
	last_node_satck->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node_satck->next->prev = last_node_satck;
	last_node_satck->next->next = NULL;
}

void	add_element(t_stack_lst_node **stack, int value)
{
	t_stack_lst_node	*node_stack;
	t_stack_lst_node	*last_node_satck;

	if (stack == NULL)
		return ;
	node_stack = (t_stack_lst_node *)malloc(sizeof(t_stack_lst_node));
	if (!node_stack)
		return ;
	node_stack->value = value;
	node_stack->next = NULL;
	if (*stack == NULL)
	{
		*stack = node_stack;
		node_stack->prev = NULL;
	}
	else
	{
		last_node_satck = find_last_node(*stack);
		last_node_satck->next = node_stack;
		node_stack->prev = last_node_satck;
	}
}

void	sort_three(t_stack_lst_node **stack)
{
	t_stack_lst_node	*larg_num;

	larg_num = get_larg_num(*stack);
	if (*stack == larg_num)
	{
		retate(stack);
		write(1, "ra\n", 3);
	}
	else if ((*stack)->next == larg_num)
	{
		reverse_retate(stack);
		write(1, "rra\n", 4);
	}
	if ((*stack)->value > (*stack)->next->value)
	{
		swap(stack);
		write(1, "sa\n", 3);
	}
}

t_stack_lst_node	*get_small_number(t_stack_lst_node *stack)
{
	t_stack_lst_node	*small_num;

	if (stack == NULL)
		return (NULL);
	small_num = stack;
	while (stack != NULL)
	{
		if (small_num->value > stack->value)
		{
			small_num = stack;
		}
		stack = stack->next;
	}
	return (small_num);
}

void	get_place_to_move(t_stack_lst_node *a, t_stack_lst_node *b)
{
	t_stack_lst_node *current_a;
	t_stack_lst_node *target_node;
	long best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->place_node = get_small_number(a);
		else
			b->place_node = target_node;
		b = b->next;
	}
}