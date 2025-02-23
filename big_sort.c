/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:20:15 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/22 22:20:17 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	pushing_to_b(t_list **head_a, t_list **head_b, int *arr, int end)
{
	int	start;
	int	size;

	size = ft_lstsize(*head_a);
	start = 0;
	while (*head_a)
	{
		if ((*head_a)->data <= arr[start])
		{
			push(head_a, head_b);
			rotate(head_b, 'b');
			update_range(&start, &end, size);
		}
		else if ((*head_a)->data <= arr[end])
		{
			push(head_a, head_b);
			if ((*head_b) && (*head_b)->next
				&& (*head_b)->data < (*head_b)->next->data)
				swap(*head_b, 98);
			update_range(&start, &end, size);
		}
		else
			rotate(head_a, 'a');
	}
}

int	max_index(t_list *head)
{
	int	max;
	int	i;
	int	i_max;

	max = head->data;
	i = 0;
	i_max = 0;
	while (head)
	{
		if (head->data > max)
		{
			max = head->data;
			i_max = i;
		}
		head = head->next;
		i++;
	}
	return (i_max);
}

void	push_to_a(t_list **head_a, t_list **head_b)
{
	while (*head_b)
	{
		if (max_index(*head_b) > (ft_lstsize(*head_b) / 2))
			while (max_index(*head_b) != 0)
				reverse(head_b, 'b');
		else
			while (max_index(*head_b) != 0)
				rotate(head_b, 'b');
		push_b(head_b, head_a);
	}
}

void	big_sort(t_list **head_a, t_list **head_b)
{
	t_list	*tmp;
	int		*arr;
	int		size_head;
	int		i;
	int		range;

	tmp = *head_a;
	i = 0;
	size_head = ft_lstsize(*head_a);
	arr = malloc(sizeof(int) * size_head);
	if (arr == NULL)
		return ;
	while (i < size_head)
	{
		arr[i] = (tmp)->data;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(arr, size_head);
	range = find_range(size_head);
	pushing_to_b(head_a, head_b, arr, range);
	push_to_a(head_a, head_b);
	free(arr);
}
