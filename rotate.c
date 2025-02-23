/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:46:42 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/07 10:46:47 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rotate(t_list **head, char t)
{
	t_list	*tmp;
	t_list	*current;

	if (!head || !*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	current = *head;
	while (current->next)
		current = current->next;
	current->next = tmp;
	if (t == 'a')
		ft_printf("ra\n");
	else if (t == 'b')
		ft_printf("rb\n");
}

void	rotate_ab(t_list **head_a, t_list **head_b)
{
	if (!*head_a || !*head_b)
		return ;
	rotate(head_a, 's');
	rotate(head_b, 's');
	ft_printf("rr\n");
}
