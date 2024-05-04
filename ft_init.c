#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/*
 *  *  atol, i need it to check eventual overflows
 *   *  converting every string into a long value
 *   */

static int ft_atoi(char *str)
{
	int i = 0;
	int num = 0;
	int sign = 1;
	while(str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if(str[i] == '+')
		i++;
	else if(str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');

		i++;
	}
	return (num  * sign);

}


void stack_init(t_stack_lst_node **a,char **argv,int c)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i] != NULL)
	{
		if(check_syntax(argv[i]) == 1)
			clean_mmr(a,argv,c);
	//	printf("aa\n");
		nbr = ft_atoi(argv[i]);
		if(nbr > INT_MAX || nbr < INT_MIN)
			clean_mmr(a, argv, c);
		if(is_repet(*a, (int)nbr))
			clean_mmr(a,argv, c);
			
		add_element(a,nbr);
		++i;
	}

	if(c== 2)
		free_array(argv);


}
