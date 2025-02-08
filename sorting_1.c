/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:45:02 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/08 13:45:04 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_two_numbers(int *a, int *b)
{
	int tmp;

	if (a == NULL || b == NULL)
		return ;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_tree_numbers(int *a, int *b, int *c)
{
	// ft_printf("a is : %d\n b is %d\n c is %d\n", a, b , c);
	int i;

	i = 0;
	while (i < 3)
	{
		if (*a > *b)
			sort_two_numbers(a , b);
		if (*b > *c)
			sort_two_numbers(b, c);
		if (*a > *c)
			sort_two_numbers(a , c);
		i++;
	}
}

//check the minmum, number of the list and do the algo HHHH

//push the mini to head_b and sort the others one

void	sort_four_numbers(list *head_a, list *head_b)
{
	
}