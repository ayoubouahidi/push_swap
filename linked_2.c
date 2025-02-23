/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:30:44 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/22 20:30:46 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*current;

	if (lst == NULL || !*lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}
