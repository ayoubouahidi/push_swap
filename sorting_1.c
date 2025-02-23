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

int	petit_node(t_list **head_a)
{
	int		pt;
	t_list	*tmp;

	tmp = *head_a;
	pt = (*head_a)->data;
	while (tmp)
	{
		if ((tmp)->data < pt)
			pt = (tmp)->data;
		tmp = (tmp)->next;
	}
	return (pt);
}

void	do_rotate(t_list **head_a, t_list **head_b)
{
	rotate(head_a, 'a');
	rotate(head_a, 'a');
	rotate(head_a, 'a');
	push(head_a, head_b);
}

void	move_min(t_list **head_a, t_list **head_b, int index)
{
	if (index == 1)
		rotate(head_a, 'a');
	else if (index == 2)
	{
		rotate(head_a, 'a');
		rotate(head_a, 'a');
	}
	else if (index == 3)
	{
		reverse(head_a, 'a');
		reverse(head_a, 'a');
	}
	else if (index == 4)
		reverse(head_a, 'a');
	push(head_a, head_b);
}

void	sort_four_numbers(t_list **head_a, t_list **head_b)
{
	int		pt;
	int		index;
	t_list	*tmp;

	tmp = *head_a;
	pt = petit_node(&tmp);
	index = find_index(&tmp, pt);
	if (index == 1)
		rotate(head_a, 'a');
	else if (index == 2)
	{
		rotate(head_a, 'a');
		rotate(head_a, 'a');
	}
	else if (index == 3)
		reverse(head_a, 'a');
	push(head_a, head_b);
	sort_tree_numbers(head_a);
	push_b(head_b, head_a);
}

void	sort_five_numbers(t_list **head_a, t_list **head_b)
{
	int		pt_1;
	int		pt_2;
	int		index;
	int		index_1;
	t_list	*tmp;

	tmp = *head_a;
	pt_1 = petit_node(&tmp);
	index = find_index(&tmp, pt_1);
	move_min(head_a, head_b, index);
	pt_2 = petit_node(head_a);
	index_1 = find_index(head_a, pt_2);
	if (index_1 == 1)
		rotate(head_a, 'a');
	else if (index_1 == 2)
	{
		rotate(head_a, 'a');
		rotate(head_a, 'a');
	}
	else if (index_1 == 3)
		reverse(head_a, 'a');
	push(head_a, head_b);
	sort_tree_numbers(head_a);
	push_b(head_b, head_a);
	push_b(head_b, head_a);
}
