/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_help2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:57:19 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/17 11:57:25 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	find_range(int size)
{
	if(size > 5 && size <= 100)
		return (size / 5);
	else if (size > 100 && size <= 500)
		return (size / 12);
	else
		return (20);
}

void	update_range(int *start, int *end, int size)
{
	if (*start < *end - 1)
		(*start)++;
	if (*end < size - 1)
		(*end)++;
}



int get_index(int value, int *arr, int size)
{
	int i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return i;
		i++;
	}
	return(-1);
}
