#include "push.h"
#include <stdlib.h>

void	swap_bubble(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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

void	big_sort(list **head_a, list **head_b)
{
	list *tmp;
	int *arr;
	int size_head;
	int i;
	head_b++;

	// ft_printf("im here");
	tmp = *head_a;
	i = 0;
	size_head = ft_lstsize(*head_a);
	arr = malloc(sizeof(int) * size_head);
	if (arr == NULL)
		return ;

	while (i < size_head)
	{
		arr[i] = (tmp)->data;
		tmp = tmp->next;
		i++;
	}
	// sorting
	// ft_printf("the first element in the arr is ")
	bubble_sort(arr, size_head);
	// printing
	i = 0;
	while (i < size_head)
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
	
	
}
