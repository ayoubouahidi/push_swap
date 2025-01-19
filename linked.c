/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:32:55 by ayouahid          #+#    #+#             */
/*   Updated: 2025/01/18 18:32:57 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list	*ft_newnode(int	data)
{
	list *tmp;

	tmp = (list	*)malloc(sizeof(list));
	if(!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}


void	ft_lstadd_back(list **lst, list *new)
{
	list	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}
