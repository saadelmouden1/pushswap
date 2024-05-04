
#include "push_swap.h"

int main(int argc,char **argv)
{
	    t_stack_lst_node *a;
	    t_stack_lst_node *b;
	    char **av;
	    a = NULL;
	    b = NULL;
	    if (1 == argc || (2 == argc && !argv[1][0]))
		    return (1);
	    else if (2 == argc)
		    av = ft_split(argv[1], ' ');
	    else
		    av = argv;
	   // printf("%s\n",av[0]);
	    stack_init(&a, av+1, argc);
	    if(!is_sorted(a))
	    {
	    	if (get_list_size(a) == 2)
	    	{
			    swap(&a);
		   	 write(1,"sa\n",3);
	    	}
	    	else if (get_list_size(a) == 3)
			    sort_three(&a);
	    	else
			    push_swap(&a, &b);	
	    }
//	if(is_sorted(a))
//		printf("jj\n");
/*
while(a!= NULL)
{
	printf("value :%d, pos: %d ,moves: %d, before_middle :%d\n",a->value,a->pos,a->moves, a->before_middle);
	if(a->prev !=NULL)
	{
	printf("%d\n",a->prev->value);
       	}else 
		printf("\n");
		a = a->next;
	  }
	 printf("*****\n");
*/ 
	stack_freeing(&a);
 }

