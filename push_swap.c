#include "push_swap.h"



void add_element(t_stack_lst_node **stack, int value)
{
    t_stack_lst_node *node_stack;
    t_stack_lst_node *last_node_satck;
    if(stack == NULL)
        return ;
    node_stack = (t_stack_lst_node*) malloc(sizeof(t_stack_lst_node));
    if(!node_stack)
        return ;
    node_stack->value = value;
    node_stack->next = NULL;
    if(*stack == NULL)
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


void sort_three(t_stack_lst_node **stack)
{
    t_stack_lst_node *larg_num;
    larg_num = get_larg_num(*stack);
 // printf("stack value :%d\n",(*stack)->value);
   //printf("larg num  value :%d\n",larg_num->value);
    if(*stack == larg_num)
    {
        retate(stack);
        write(1,"ra\n",3);
    }
    else if((*stack)->next ==  larg_num)
    {
        reverse_retate(stack);
        write(1,"rra\n",4);
    }
    if((*stack)->value > (*stack)->next->value)
    {
        swap(stack);
        write(1,"sa\n",3);
    }
}





t_stack_lst_node *get_small_number(t_stack_lst_node *stack)
{
    t_stack_lst_node *small_num;
    if(stack == NULL)
        return NULL;
    small_num = stack;
    while(stack != NULL)
    {
        if(small_num->value > stack->value)
        {
            small_num = stack;
        }
        stack = stack->next;
    }
    return (small_num);
}

void get_place_to_move(t_stack_lst_node *a, t_stack_lst_node *b)
{
   t_stack_lst_node	*current_a;
	t_stack_lst_node	*target_node;
	long			best_match_index;

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

void get_update_pos(t_stack_lst_node *stack)
{
    int  i;
    int c;
    i = 0;
    if(stack == NULL)
        return;
     c = get_list_size(stack) / 2;
     while(stack)
     {
       
        stack->pos =i;
        if(i > c)
            stack->before_middle = false;
        else
            stack->before_middle = true;

        stack = stack->next;
        i++;
     }
}



void get_small_num_moves(t_stack_lst_node *stack)
{
    long mn;
    t_stack_lst_node *mn_moves_node;

    if(stack == NULL)
        return;
    mn = LONG_MAX;
    while(stack)
    {
        if(stack->moves < mn)
        {
            mn = stack->moves;
            mn_moves_node = stack;
        }
        stack = stack->next;
    }
    mn_moves_node->small_n_moves = true;
}

void set_moves(t_stack_lst_node *a, t_stack_lst_node *b)
{
    int size_a;
    int size_b;

    size_a = get_list_size(a);
    size_b = get_list_size(b);

    while(b)
    {
      
        b->moves = b->pos;
        if(!(b->before_middle))
        {
            
            b->moves = size_b - (b->pos);
        }
            
           
        
        if(b->place_node->before_middle)
        {
                            
            b->moves += b->place_node->pos;
        }
        else
            b->moves += size_a - (b->place_node->pos);
        b = b->next;
    }

}

t_stack_lst_node *get_smallest_moves_nd(t_stack_lst_node *stack)
{
	if(stack == NULL)
	{
		return NULL;
	}
	while(stack != NULL)
	{
		if(stack->small_n_moves)
			return stack;
		stack = stack->next;
	}
	return NULL;
}
void final_steps(t_stack_lst_node **stack,
			t_stack_lst_node *top_node,
			char nm_stack)
{
	while(*stack != top_node)
	{
		if(nm_stack == 'a')
		{
			if(top_node->before_middle)
			{
				retate(stack);
				write(1,"ra\n",3);
			}
			else
			{
				reverse_retate(stack);
				write(1,"rra\n",4);
			}
		}
		else if(nm_stack == 'b')
		{
			if(top_node->before_middle)
			{
				retate(stack);
				write(1,"rb\n",3);
			}
			else
			{
				reverse_retate(stack);
				write(1,"rrb\n",4);
			}

		}
	}
}

void move_nodes(t_stack_lst_node **a,t_stack_lst_node **b)
{
	t_stack_lst_node *node_to_move;
	node_to_move = get_smallest_moves_nd(*b);

//	printf("smaalest:%d\n",node_to_move->value);
	if(node_to_move->before_middle 
		&& node_to_move->place_node->before_middle)
	{
		//printf("hh\n");
		while(*a != node_to_move->place_node && *b != node_to_move)
		{
		retate(a);
		retate(b);
		write(1,"rr\n",3);
		}
		get_update_pos(*a);
		get_update_pos(*b);
	}
	else if(!(node_to_move->before_middle)
		&& !(node_to_move->place_node->before_middle))
	{
		//printf("ff\n");
		while( *a != node_to_move->place_node && *b != node_to_move) 
		{	
		reverse_retate(a);
		reverse_retate(b);
		write(1,"rrr\n",4);
		}
		get_update_pos(*a);
		get_update_pos(*b);
		//write(1,"rrr\n",4);
	}
	final_steps(b,node_to_move,'b');
	final_steps(a,node_to_move->place_node,'a');
	push_stack(a,b);
	write(1,"pa\n",3);

}
void refresh_nodes(t_stack_lst_node *a,t_stack_lst_node *b)
{
	get_update_pos(a);
	get_update_pos(b);
	get_place_to_move(a,b);
	set_moves(a,b);
	get_small_num_moves(b);
}

void push_swap(t_stack_lst_node **stack_a, t_stack_lst_node **stack_b)
{
    int i;
    t_stack_lst_node *small_node;


    i = get_list_size(*stack_a);
    while(i > 3)
    {
	    push_stack(stack_b,stack_a);
	    write(1,"pb\n",3);
	    i--;
    }
    sort_three(stack_a);
   // printf("ll\n");
    while(*stack_b != NULL)
    {
	  //  printf("gg\n");
	    refresh_nodes(*stack_a,*stack_b);
	    move_nodes(stack_a,stack_b);
    }
   // printf("uu\n");
    get_update_pos(*stack_a);
    small_node  = get_small_number(*stack_a);
    if(small_node->before_middle)
    {
	    while(*stack_a != small_node)
	    {
		    retate(stack_a);
		    write(1,"ra\n",3);
	    }
	    
    }
    else
    {
	    while(*stack_a != small_node)
	    {
		    reverse_retate(stack_a);
		    write(1,"rra\n",4);
	    }
    }

}






/*
int main(int argc,char **argv)
{
    t_stack_lst_node *a;
     t_stack_lst_node *b;
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
        printf("value :%d, pos: %d ,moves: %d, before_middle :%d\n",a->value,a->pos,a->moves, a->before_middle);
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
        printf("value :%d, pos: %d ,moves: %d, before_middle :%d,plmpos :%d, small:%d\n",b->value,b->pos,b->moves, b->before_middle, b->place_node->pos, b->small_n_moves);
        
        b = b->next;
    }

      printf("*****\n");
      
      t_stack_lst_node *d = get_smallest_moves_nd(b);
      printf("%d\n",d->value);
 
}
*/

