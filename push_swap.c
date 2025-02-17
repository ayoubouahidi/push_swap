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


#include <stdlib.h>
#include "push.h"
#include "./ft_printf/ft_printf.h"
#include <stdio.h>

int	check_max(long nbr)
{
	if (nbr > 2147483647 || nbr > -2147483648)
		return (0);
	return (1);
}

int	lenght(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
		i++;
	return (i);
}

char	*isvalid(char *av)
{
	int	i;

	i = 0;
	if (av[0] != '-' && av[0] != '+' && !ft_isdigit(av[0]))
		return (NULL);
	if((av[0] == '-' || av[0] == '+') && lenght(av) == 1)
		return (NULL);
	i++;
	while (av[i] !=  '\0')
	{
		if(!ft_isdigit(av[i]))
			return (NULL);
		i++;
	}
	return ("is valid ");
}

void	printlist(list *head)
{
	list	*tmp;
	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int	check(list *head)
{	
	int	data_act;
	list *tmp;

	while (head)
	{
		data_act = head->data;
		head = head->next;
		tmp = head;
		while (tmp)
		{
			if (data_act == tmp->data)
				return 1;
			tmp = tmp->next;
		}
	}
	return 0;
}


list	*stock_arg(int ac, char **av)
{
	list *head;
	int	i;
	int j;
	list *new;
	char **str_arg;

	i = 1;
	head = NULL;
	if (ac >= 2)
	{
		while(av[i])
		{
			if(av[i][0] == '\0')
				return (NULL);
			j = 0;
			while (av[i][j])
			{	
				if (!ft_isdigit(av[i][j]) && av[i][j] != 32 && (av[i][j] != '+' && av[i][j] != '-'))
					return (NULL);
				j++;
			}
			if (ft_strchr(av[i], 32))
			{
				j = 0;
				str_arg = ft_split(av[i], 32);
				while (str_arg[j])
				{
					if (!isvalid(str_arg[j]) || check_max(ft_atoi(str_arg[j])))
						return (NULL);
					new = ft_newnode(ft_atoi(str_arg[j]));
					ft_lstadd_back(&head, new);
					j++;
				}
			}
			else
			{
				if (!isvalid(av[i]) || check_max(ft_atoi(av[i])))
					return (NULL);
				new = ft_newnode(ft_atoi(av[i]));
				ft_lstadd_back(&head, new);
			}
			i++;
		}
		if (check(head) == 1)
			return (NULL);
		return(head);
	}
	else
		return (NULL);
}

int	main(int ac, char **av)
{
	list	*head;
	list	*head_b;
	int	size_head;

	if(ac == 1)
		return (0);
	head = stock_arg(ac , av);
	head_b = NULL;
	if (stock_arg(ac , av) == NULL)
		return(ft_printf("Error"),1);
	if (check_if_sorted(&head))
	{
		size_head = ft_lstsize(head);
		if (size_head <= 2)
			sort_two_numbers(&head);
		else if(size_head <= 3)
			sort_tree_numbers(&head);
		else if(size_head <= 4)
			sort_four_numbers(&head, &head_b);
		else if(size_head <= 5)
			sort_five_numbers(&head, &head_b);
		else
			big_sort(&head, &head_b);
	}
}

