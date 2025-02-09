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




int	find_index(list	**head_a, int pt)
{
	int	index_min;
	int index;

	index = 0;
	while ((*head_a)->next != NULL)
	{
		if((*head_a)->data == pt)
			index_min = index;
		index++;
		*head_a = (*head_a)->next;
	}
	return (index_min);
}


int	petit_node(list **head_a)
{
	int pt;


	list *tmp;

	tmp = *head_a;
	pt = (*head_a)->data;
	while(tmp)
	{
		if((tmp)->data < pt)
			pt = (tmp)->data;
		tmp = (tmp)->next;
	}
	return (pt);
}
void	do_rotate(list **head_a, list **head_b)
{
	rotate(head_a, 'a');
	rotate(head_a, 'a');
	rotate(head_a, 'a');
	push(head_a, head_b);
}

void	sort_four_numbers(list **head_a, list **head_b)
{

	int pt;
	int index;
	list *tmp;

	tmp = *head_a;
	pt = petit_node(&tmp);
	index = find_index(&tmp, pt);
	if (index == 1)
	{
		rotate(head_a, 'a');
		push(head_a, head_b);
	}
	else if (index == 2)
	{
		rotate(head_a, 'a');
		rotate(head_a, 'a');
		push(head_a, head_b);
	}
	else if (index == 0)
		push(head_a , head_b);
	sort_tree_numbers(&(*head_a)->data, &(*head_a)->next->data, &(*head_a)->next->next->data);
	push_b(head_b, head_a);
}

void	move_min(list **head_a, list **head_b, int index)
{
	if(index == 1)
		rotate(head_a, 'a');
	else if (index == 2)
	{
		rotate(head_a, 'a');
		rotate(head_a, 'a');                                       
	}
	else if(index == 3)
		do_rotate(head_a, head_b);
	else if(index == 4)
	{
		rotate(head_a, 'a');
		rotate(head_a, 'a');
		rotate(head_a, 'a');
		rotate(head_a, 'a');
	}
}


void	sort_five_numbers(list **head_a, list **head_b)
{
	int	pt_1;
	int pt_2;
	int	index;
	
	list *tmp;

	tmp = *head_a;
	pt_1 = petit_node(&tmp);
	index = find_index(&tmp, pt_1);
	move_min(head_a, head_b, index);
	push(head_a, head_b);
	pt_2 = petit_node(&tmp);


	// sort_four_numbers(head_a, head_b);
	// sort_two_numbers(&(*head_b)->data, &(*head_b)->next->data);
	push_b(head_b, head_a);
	push_b(head_b, head_a);
}
