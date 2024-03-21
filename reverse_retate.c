#include "push_swap.h"

void reverse_retate(t_stack_lst_node **stack)
{
    t_stack_lst_node *first_node;
    t_stack_lst_node *last_node;

    if(stack ==NULL || *stack == NULL || (*stack)->next == NULL)
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