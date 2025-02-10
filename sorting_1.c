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

void	sort_two_numbers(list **head)
{
	if (&(*head)->data == NULL || &(*head)->next->data == NULL)
		return ;
	ft_printf("head data is : %d\n", (*head)->data);
	if ((*head)->data > (*head)->next->data) 
	{
		swap(*head, 'a');
	}
}

void	sort_tree_numbers(list **head)
{
		if ((*head) == NULL || (*head)->next == NULL || (*head)->next->next == NULL) {
     	   return;
	    }
		// ft_printf("head data is : %d\n", (*head)->data);
		if ((*head)->data > (*head)->next->data)
			sort_two_numbers(head);
		if ((*head)->next->data > (*head)->next->next->data)
			sort_two_numbers(head);
		if ((*head)->data > (*head)->next->data)
			sort_two_numbers(head);
		// i++;
}

//check the minmum, number of the list and do the algo HHHH
//push the mini to head_b and sort the others one




int	find_index(list	**head_a, int pt)
{
	int	index_min;
	int index;
	list *tmp;

	tmp = *head_a;
	index = 0;
	while (tmp != NULL)
	{
		if((tmp)->data == pt)
			index_min = index;
		index++;
		tmp = (tmp)->next;
		// ft_printf("test\n");
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
	sort_tree_numbers(head_a);
	push_b(head_b, head_a);
}

void	move_min(list **head_a,  int index)
{
	if(index == 1)
		rotate(head_a, 'a');
	else if (index == 2)
	{
		rotate(head_a, 'a');
		rotate(head_a, 'a');                                       
	}
	else if(index == 3)
	{
		rotate(head_a, 'a');
		rotate(head_a, 'a');
		rotate(head_a, 'a');
	}
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
	int	index_1;
	list *tmp;

	tmp = *head_a;
	pt_1 = petit_node(&tmp);
	index = find_index(&tmp, pt_1);
	move_min(head_a, index);
	push(head_a, head_b);

	tmp = *head_a;
	pt_2 = petit_node(&tmp);
	index_1 = find_index(&tmp, pt_2);
	move_min(head_a,  index_1);
	push(head_a, head_b);
	// ft_printf("the petit : %d\n", (tmp)->data);
	tmp = *head_a;
	sort_tree_numbers(head_a);
	// sort_two_numbers(&(*head_b)->data, &(*head_b)->next->data);
	push_b(head_b, head_a);
	push_b(head_b, head_a);
	// sort_tree_numbers(head_a);
}
