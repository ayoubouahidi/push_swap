/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:15:53 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/07 17:15:56 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push.h"

void	reverse(list **head, char t)
{
	list *last;
	list *tmp;

	if (!*head)
		return ;
	if (ft_lstsize(*head) == 1)
		return ;
	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	last = ft_lstlast(*head);
	tmp->next = NULL;
	ft_lstadd_front(head, last);
	if (t == 'a')
		ft_printf("rra\n");
	else if (t == 'b')
		ft_printf("rrb\n");
}

void	reverse_ab(list **head_a, list **head_b)
{
	if (!*head_a || !*head_b)
		return ;
	reverse(head_a, 's');
	reverse(head_b, 's');
	ft_printf("rrr\n");
}
