/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:42:14 by ayouahid          #+#    #+#             */
/*   Updated: 2025/01/18 12:42:16 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include "push.h"
#include <stdio.h>
#include <stdlib.h>

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	string_process(char **str_arg, t_list **head)
{
	t_list	*new;
	int		j;

	j = 0;
	if (!str_arg[j])
		return (0);
	while (str_arg[j])
	{
		if (!isvalid(str_arg[j]))
		{
			free_split(str_arg);
			ft_lstclear(head);
			return (0);
		}
		new = ft_newnode(ft_atoi(str_arg[j]));
		ft_lstadd_back(head, new);
		j++;
	}
	free_split(str_arg);
	return (1);
}

int	num_process(char *arg, t_list **head)
{
	t_list	*new;

	if (!isvalid(arg))
	{
		ft_lstclear(head);
		return (0);
	}
	new = ft_newnode(ft_atoi(arg));
	ft_lstadd_back(head, new);
	return (1);
}

t_list	*stock_arg(int ac, char **av)
{
	t_list	*head;
	int		i;

	i = 1;
	head = NULL;
	if (ac < 2)
		return (NULL);
	while (av[i])
	{
		if (av[i][0] == '\0' || !is_valid_arg(av[i]))
			return (ft_lstclear(&head), NULL);
		if (ft_strchr(av[i], 32))
		{
			if (!string_process(ft_split(av[i], 32), &head))
				return (ft_lstclear(&head), NULL);
		}
		else if (!num_process(av[i], &head))
			return (NULL);
		i++;
	}
	if (check(head) == 1)
		return (ft_lstclear(&head), NULL);
	return (head);
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*head_b;
	int		size_head;

	if (ac == 1)
		return (0);
	head = stock_arg(ac, av);
	head_b = NULL;
	if (head == NULL)
		return (ft_printf("Error"), 1);
	if (check_if_sorted(&head))
	{
		size_head = ft_lstsize(head);
		if (size_head <= 2)
			sort_two_numbers(&head);
		else if (size_head <= 3)
			sort_tree_numbers(&head);
		else if (size_head <= 4)
			sort_four_numbers(&head, &head_b);
		else if (size_head <= 5)
			sort_five_numbers(&head, &head_b);
		else
			big_sort(&head, &head_b);
	}
	ft_lstclear(&head);
}
