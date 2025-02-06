/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:39:03 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/06 15:39:10 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>

void	push(list **head_a, list **head_b)
{
	list *tmp;

	if (*head_a == NULL)
		return;
	tmp = *head_a;
	*head_a = tmp->next;
	ft_lstadd_front(head_b, tmp);
	ft_printf("pa\n");
}

void	push_b(list **head_b, list **head_a)
{
	list *tmp;

	if (*head_b == NULL)
		return;
	tmp = *head_b;
	*head_b = tmp->next;
	ft_lstadd_front(head_a, tmp);
	ft_printf("pb\n");
}
