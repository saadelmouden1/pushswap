/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:42:42 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/08 00:47:03 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static long	ft_atoi(char *str)
{
	int	i;
	long	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}
void	stack_init(t_stack_lst_node **a, char **argv, int c)
{
	long	nbr;
	int		i;
	char **v;

	i = 0;
	while (argv[i] != NULL)
	{
		v = ft_split(argv[i] , ' ');
		if(v[0]== NULL)
				clean_mmr(a, v, c);
		int n= 0;
		while(v[n]!= NULL)
		{
			if (check_syntax(v[n]) == 1)
				clean_mmr(a, v, c);
			nbr = ft_atoi(v[n]);
			if ((nbr > INT_MAX || nbr < INT_MIN) || is_repet(*a, (int)nbr) )
				clean_mmr(a, v, c);
			add_element(a, nbr);
			++n;
		}
		if(v)
				free_array(v);
		++i;
	}
}
