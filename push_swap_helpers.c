#include "push_swap.h"


t_stack_lst_node *get_larg_num(t_stack_lst_node *stack)
{
    t_stack_lst_node *larg_num;
    if(stack == NULL)
        return NULL;
    larg_num = stack;
    while(stack != NULL)
    {
        if(larg_num->value < stack->value)
        {
            larg_num = stack;
        }
        stack = stack->next;
    }
    return (larg_num);
}

int get_list_size(t_stack_lst_node *stack)
{
    int i = 0;
    while(stack != NULL)
    {
        i++;
        stack = stack->next;
    }
    return i;
}

t_stack_lst_node *find_last_node(t_stack_lst_node *first_element)
{
     
    if(first_element == NULL)
        return (NULL);
   
    while(first_element->next != NULL)
        first_element = first_element->next;
    return(first_element);

}