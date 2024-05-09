/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_retate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:43:27 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/09 00:11:49 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_retate(t_stack_lst_node **stack)
{
	t_stack_lst_node	*first_node;
	t_stack_lst_node	*last_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	last_node = find_last_node(*stack);
	first_node = (*stack);
	first_node->prev = last_node;
	*stack = last_node;
	last_node->prev->next = NULL;
	(*stack)->next = first_node;
	(*stack)->prev = NULL;
}

void	get_update_pos(t_stack_lst_node *stack)
{
	int	i;
	int	c;

	i = 0;
	if (stack == NULL)
		return ;
	c = get_list_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i > c)
			stack->before_middle = false;
		else
			stack->before_middle = true;
		stack = stack->next;
		i++;
	}
}

void	get_small_num_moves(t_stack_lst_node *stack)
{
	long				mn;
	t_stack_lst_node	*mn_moves_node;

	if (stack == NULL)
		return ;
	mn = LONG_MAX;
	while (stack)
	{
		if (stack->moves < mn)
		{
			mn = stack->moves;
			mn_moves_node = stack;
		}
		stack = stack->next;
	}
	mn_moves_node->small_n_moves = true;
}

void	set_moves(t_stack_lst_node *a, t_stack_lst_node *b)
{
	int	size_a;
	int	size_b;

	size_a = get_list_size(a);
	size_b = get_list_size(b);
	while (b)
	{
		b->moves = b->pos;
		if (!(b->before_middle))
		{
			b->moves = size_b - (b->pos);
		}
		if (b->place_node->before_middle)
		{
			b->moves += b->place_node->pos;
		}
		else
			b->moves += size_a - (b->place_node->pos);
		b = b->next;
	}
}

t_stack_lst_node	*get_smallest_moves_nd(t_stack_lst_node *stack)
{
	if (stack == NULL)
	{
		return (NULL);
	}
	while (stack != NULL)
	{
		if (stack->small_n_moves)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
