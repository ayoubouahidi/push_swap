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

void	rotate(list **head, char t)
{
	list	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	ft_lstadd_back(head, tmp);
	if (t == 'a')
		ft_printf("ra\n");
	else if (t == 'b')
		ft_printf("rb\n");
}

void	rotate_ab(list **head_a, list **head_b)
{
	if(!*head_a || !*head_b)
		return ;
	rotate(head_a, 's');
	rotate(head_b, 's');
	ft_printf("rr\n");
}