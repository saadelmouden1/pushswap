/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:43:14 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/07 02:43:15 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_lst_node	*get_larg_num(t_stack_lst_node *stack)
{
	t_stack_lst_node	*larg_num;

	if (stack == NULL)
		return (NULL);
	larg_num = stack;
	while (stack != NULL)
	{
		if (larg_num->value < stack->value)
		{
			larg_num = stack;
		}
		stack = stack->next;
	}
	return (larg_num);
}

int	get_list_size(t_stack_lst_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack_lst_node	*find_last_node(t_stack_lst_node *first_element)
{
	if (first_element == NULL)
		return (NULL);
	while (first_element->next != NULL)
		first_element = first_element->next;
	return (first_element);
}

bool	is_sorted(t_stack_lst_node *list)
{
	if (list == NULL)
		return (1);
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
			return (false);
		list = list->next;
	}
	return (true);
}
