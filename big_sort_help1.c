/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_help1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:49:19 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/17 11:49:22 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_bubble(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_bubble2(list **a)
{
	list *tmp;

	if(!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	ft_lstadd_front(a, tmp);
}

void	bubble_sort(int *arr,int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_bubble(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	
}

int	check_if_in_range(int head_data, int start , int range,int *arr)
{
	int	i;

	i = start + 1;
    while (i < start + range)  
    {
        if (head_data == arr[i])  
            return (1);
        i++;
    }
    return (0); 
}

int	check_if_in(int head_data, int start, int *arr)
{
	int	i;

	i = 0;
	while (i <= start)
	{
		if (head_data == arr[i])
			return (1);
		i++;
	}
	return (0);
}
