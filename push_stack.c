#include "push_swap.h"

void push_stack(t_stack_lst_node **dest, t_stack_lst_node **src)
{
//  printf("ff");
    t_stack_lst_node	*node_to_push;

	if (NULL == *src || src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
       
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
  // printf("j");
}
