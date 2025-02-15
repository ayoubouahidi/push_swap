#include "push.h"
#include <stdlib.h>

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// void	bubble_sort(int *arr,)
// {
	    //  
// }

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
	// printing
	i = 0;
	while (i < size_head)
	{
		ft_printf("%d\n", arr[i]);
		i++;
	}
	
	
}
