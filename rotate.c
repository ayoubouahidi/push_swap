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

// void	rotate(list **head, char t)
// {
// 	int i = 0;
// 	list	*tmp;
// 	list	*assist;

// 	if (!head || !*head || !(*head)->next)
// 		return ;
// 	tmp = *head;
// 	ft_printf("step %d\n", i++);
// 	*head = (*head)->next;
// 	ft_printf("step %d\n", i++);
// 	assist = *head;
// 	ft_printf("step %d\n", i++);
// 	tmp->next = NULL;
// 	ft_printf("step %d\n", i++);
// 	while (assist && assist->next)
// 	{
// 		ft_printf("%p\n", assist);
// 		ft_printf("%p\n", assist->next);
// 		assist = assist->next;
// 		ft_printf("step %d in loop\n", i++);
// 	}
// 	assist->next = tmp;
// 	ft_printf("step %d\n", i++);
// 	/* ft_lstadd_back(head, tmp); */
// 	if (t == 'a')
// 		ft_printf("ra\n");
// 	else if (t == 'b')
// 		ft_printf("rb\n");
// }

void rotate(list **head, char t)
{
    if (!head || !*head || !(*head)->next)
        return;
    list *tmp = *head;
    *head = (*head)->next;
    tmp->next = NULL;

    // Add the original head to the end of the list
    list *current = *head;
    while (current->next)
        current = current->next;
    current->next = tmp;

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