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



void	free_split(char **str)
{
	int i;

	i = 0;
	if(!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_exit_1(long result, 	char **str_arg)
{
	if (result > 2147483647  || result < -2147483648)
	{
		ft_printf("Error");
		free_split(str_arg);
		exit(1);
	}
}

void	free_exit_2(long result, 	list **head)
{
	if (result > 2147483647  || result < -2147483648)
	{
		ft_printf("Error");
		ft_lstclear(head);
		exit(1);
	}
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
	long result;

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
	result = ft_atoi(av);
	if (result > 2147483647  || result < -2147483648)
		return (NULL);
	// printf("the result is : %ld\n", result);
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
					if (!isvalid(str_arg[j]))
					{
						free_split(str_arg);
						ft_lstclear(&head);
						return (NULL);
					}
					// free_exit_1(ft_atoi(str_arg[i]), str_arg);
					new = ft_newnode(ft_atoi(str_arg[j]));
					ft_lstadd_back(&head, new);
					j++;
				}
				free_split(str_arg);
			}
			else
			{

				if (!isvalid(av[i]))
				{
					ft_lstclear(&head);
					return (NULL);
				}
				// free_exit_2(ft_atoi(str_arg[i]), &head);
				new = ft_newnode(ft_atoi(av[i]));
				ft_lstadd_back(&head, new);
			}
			i++;
		}
		if (check(head) == 1)
		{
			ft_lstclear(&head);
			return (NULL);
		}
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
	if (head == NULL)
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
	// printlist(head);
	ft_lstclear(&head);
}
