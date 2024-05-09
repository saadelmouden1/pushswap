/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:42:59 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/09 00:50:38 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_sort(t_stack_lst_node **a, t_stack_lst_node **b)
{
	if (get_list_size(*a) == 2)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (get_list_size(*a) == 3)
		sort_three(a);
	else
		push_swap(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_lst_node	*a;
	t_stack_lst_node	*b;
	char				**av;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (2 == argc && !argv[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	av = argv;
	stack_init(&a, av + 1);
	if (!is_sorted(a))
	{
		handle_sort(&a, &b);
	}
	stack_freeing(&a);
}
