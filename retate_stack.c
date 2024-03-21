#include "push_swap.h"


void retate(t_stack_lst_node **stack)
{
    t_stack_lst_node *last_node_satck;
    if(stack == NULL || *stack == NULL)
    {

     //printf("jj");
        return ;
    }
   
    last_node_satck = find_last_node(*stack);
    last_node_satck->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node_satck->next->prev = last_node_satck;
    last_node_satck->next->next = NULL;
}