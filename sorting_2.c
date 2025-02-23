/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:39:16 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/22 20:39:17 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_two_numbers(t_list **head)
{
	if (*head == NULL || (*head)->next == NULL)
		return ;
	if ((*head)->data > (*head)->next->data)
	{
		swap(*head, 'a');
	}
}

void	sort_tree_numbers(t_list **head)
{
	if (((*head)->next->next->data < (*head)->data)
		&& ((*head)->next->data < (*head)->next->next->data))
		rotate(head, 'a');
	else if ((*head) == NULL
		|| (*head)->next == NULL || (*head)->next->next == NULL)
		return ;
	else if ((*head)->data > (*head)->next->data)
		sort_two_numbers(head);
	if ((*head)->next->data > (*head)->next->next->data)
	{
		reverse(head, 'a');
		sort_two_numbers(head);
		if ((*head)->data > (*head)->next->data)
			sort_two_numbers(head);
	}
}

int	check_if_sorted(t_list **head_a)
{
	t_list	*tmp;

	tmp = *head_a;
	if (*head_a == NULL || (*head_a)->next == NULL)
		return (0);
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_index(t_list **head_a, int pt)
{
	int		index_min;
	int		index;
	t_list	*tmp;

	tmp = *head_a;
	index = 0;
	while (tmp != NULL)
	{
		if ((tmp)->data == pt)
			index_min = index;
		index++;
		tmp = (tmp)->next;
	}
	return (index_min);
}
