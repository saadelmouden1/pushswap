#include "push_swap.h"



void swap(t_stack_lst_node **stack)
{
    t_stack_lst_node *nd;
      if(stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {

     printf("jj");
        return ;
    }
    nd = *stack;

    (*stack) = (*stack)->next;
    nd->next = (*stack)->next;
    (*stack)->next= nd;
   
    (*stack)->prev = NULL;
    nd->prev = (*stack);
    if(nd->next)
     nd->next->prev = nd;
}