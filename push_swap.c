/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:43:17 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/07 20:38:47 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_nodes(t_stack_lst_node **a, t_stack_lst_node **b)
{
	t_stack_lst_node	*node_to_move;

	node_to_move = get_smallest_moves_nd(*b);
	//	printf("smaalest:%d\n",node_to_move->value);
	if (node_to_move->before_middle && node_to_move->place_node->before_middle)
	{
		// printf("hh\n");
		while (*a != node_to_move->place_node && *b != node_to_move)
		{
			retate(a);
			retate(b);
			write(1, "rr\n", 3);
		}
		get_update_pos(*a);
		get_update_pos(*b);
	}
	else if (!(node_to_move->before_middle)
		&& !(node_to_move->place_node->before_middle))
	{
		// printf("ff\n");
		while (*a != node_to_move->place_node && *b != node_to_move)
		{
			reverse_retate(a);
			reverse_retate(b);
			write(1, "rrr\n", 4);
		}
		get_update_pos(*a);
		get_update_pos(*b);
		// write(1,"rrr\n",4);
	}
	final_steps(b, node_to_move, 'b');
	final_steps(a, node_to_move->place_node, 'a');
	push_stack(a, b);
	write(1, "pa\n", 3);
}


void	refresh_nodes(t_stack_lst_node *a, t_stack_lst_node *b)
{
	get_update_pos(a);
	get_update_pos(b);
	get_place_to_move(a, b);
	set_moves(a, b);
	get_small_num_moves(b);
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
	// printf("ll\n");
	while (*stack_b != NULL)
	{
		refresh_nodes(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	// printf("uu\n");
	get_update_pos(*stack_a);
	small_node = get_small_number(*stack_a);
	if (small_node->before_middle)
	{
		while (*stack_a != small_node)
		{
			retate(stack_a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (*stack_a != small_node)
		{
			reverse_retate(stack_a);
			write(1, "rra\n", 4);
		}
	}
}

/*
int	main(int argc,char **argv)
{
	t_stack_lst_node	*a;
		t_stack_lst_node *b;
	t_stack_lst_node	*d;

	a = NULL;
		b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
				return (1);
		else if (2 == argc)
					argv = ft_split(argv[1], ' ');
			stack_init(&a, argv + 1);
	push_swap(&a,&b);
	add_element(&a,8);
		add_element(&a,7);
   add_element(&a,2);
		add_element(&a,11);
				add_element(&a,6);
				add_element(&a,5);
				add_element(&a,100);
				add_element(&a,20);
   //stack_init(&a, argv + 1, 2 == argc);
  push_swap(&a,&b);
 while(a!= NULL)
	{
		printf("value :%d, pos: %d ,moves: %d,
			before_middle :%d\n",a->value,a->pos,a->moves, a->before_middle);
		// if(f1->prev !=NULL)
		// {
		//     printf("%d\n",f1->prev->value);
		// }else
		//     printf("\n");
		a = a->next;
	}
printf("*****\n");
 while(b != NULL)
	{
		printf("value :%d, pos: %d ,moves: %d, before_middle :%d,plmpos :%d,
			small:%d\n",b->value,b->pos,b->moves, b->before_middle,
			b->place_node->pos, b->small_n_moves);
		b = b->next;
	}
		printf("*****\n");
		d = get_smallest_moves_nd(b);
		printf("%d\n",d->value);
}
*/
