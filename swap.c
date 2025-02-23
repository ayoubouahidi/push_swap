/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:06:48 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/06 10:08:03 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <unistd.h>

void	swap(t_list *head, char type)
{
	int	n;
	int	tmp;

	n = ft_lstsize(head);
	if (type == 'a')
		ft_printf("sa\n");
	else if (type == 'b')
		ft_printf("sb\n");
	if (n <= 1)
		return ;
	else
	{
		tmp = head->data;
		head->data = head->next->data;
		head->next->data = tmp;
	}
}

void	swap_ab(t_list *head_a, t_list *head_b)
{
	swap(head_a, 's');
	swap(head_b, 's');
	ft_printf("ss\n");
}
