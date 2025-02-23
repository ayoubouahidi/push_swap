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

t_list	*ft_newnode(int data)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

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

int	ft_lstsize(t_list *lst)
{
	int	cmpt;

	cmpt = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		cmpt++;
	}
	return (cmpt);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
		{
			last = lst;
		}
		lst = lst->next;
	}
	return (last);
}
