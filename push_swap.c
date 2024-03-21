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
    printf("stack value :%d\n",(*stack)->value);
     printf("larg num  value :%d\n",larg_num->value);
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

void sort_five(t_stack_lst_node **stack_a, t_stack_lst_node **stack_b)
{
    int i;

    i = get_list_size(*stack_a);
     //push_stack(stack_b,stack_a);
    printf("d\n");
    while(i != 3)
    {
        push_stack(stack_b,stack_a);
        i--;
    }
    sort_three(stack_a);

     get_update_pos(*stack_a);
          get_update_pos(*stack_b);
          get_place_to_move(*stack_a, *stack_b);
          set_moves(*stack_a, *stack_b);
          get_small_num_moves(*stack_b);

    

}

int main()
{
    t_stack_lst_node *f1;
     t_stack_lst_node *b;
    f1 = NULL;
        b = NULL;

    add_element(&f1,8);

      add_element(&f1,7);
   add_element(&f1,2);
      add_element(&f1,11);
            
             add_element(&f1,6);
              add_element(&f1,5);
             add_element(&f1,10);
                add_element(&f1,20);

    
  sort_five(&f1,&b);

 while(f1 != NULL)
    {
        printf("value :%d, pos: %d ,moves: %d, before_middle :%d\n",f1->value,f1->pos,f1->moves, f1->before_middle);
        // if(f1->prev !=NULL)
        // {
        //     printf("%d\n",f1->prev->value);
        // }else
        //     printf("\n");
        f1 = f1->next;
    }
printf("*****\n");
 
 while(b != NULL)
    {
        printf("value :%d, pos: %d ,moves: %d, before_middle :%d,plmpos :%d, small:%d\n",b->value,b->pos,b->moves, b->before_middle, b->place_node->pos, b->small_n_moves);
        
        b = b->next;
    }

      printf("*****\n");
 
}