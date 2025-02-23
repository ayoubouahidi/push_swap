/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:07:12 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/22 21:07:16 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
	int		i;
	long	result;
	int		err;

	i = 0;
	if (av[0] != '-' && av[0] != '+' && !ft_isdigit(av[0]))
		return (NULL);
	if ((av[0] == '-' || av[0] == '+') && lenght(av) == 1)
		return (NULL);
	i++;
	while (av[i] != '\0')
	{
		if (!ft_isdigit(av[i]))
			return (NULL);
		i++;
	}
	err = 0;
	result = ft_atoi_err(av, &err);
	(void)result;
	if (err)
		return (NULL);
	return ("is valid ");
}

void	printlist(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int	check(t_list *head)
{
	int		data_act;
	t_list	*tmp;

	while (head)
	{
		data_act = head->data;
		head = head->next;
		tmp = head;
		while (tmp)
		{
			if (data_act == tmp->data)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

int	is_valid_arg(char *arg)
{
	int	j;

	j = 0;
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]) && arg[j] != 32 && (arg[j] != '+'
				&& arg[j] != '-'))
			return (0);
		j++;
	}
	j = 0;
	while (arg[j] == ' ')
		j++;
	if (arg[j] == '\0')
		return (0);
	return (1);
}
