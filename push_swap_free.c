/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:43:10 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/09 00:49:27 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_freeing(t_stack_lst_node **list)
{
	t_stack_lst_node	*i;
	t_stack_lst_node	*j;

	if (list == NULL)
		return ;
	i = *list;
	while (i)
	{
		j = i->next;
		free(i);
		i = j;
	}
	*list = NULL;
}

void	free_array(char **str)
{
	int	i;

	if (str == NULL || *str == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	clean_mmr(t_stack_lst_node **a, char **av)
{
	stack_freeing(a);
	if (av)
		free_array(av);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9')))
		return (1);
	if ((str[0] == '+' || str[0] == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_repet(t_stack_lst_node *a, int n)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}
