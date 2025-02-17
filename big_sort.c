#include "push.h"



void	pushing_to_b(list **head_a, list **head_b, int *arr, int end, int size)
{
	int start;

	// tmp = *head_a;
	start = 0;
    // printlist(*head_a);
	while (*head_a)
	{
		// ft_printf("the head a data is %d\n", (*head_a)->data);
		// ft_printf("a data is %d\n", (*head_a)->data);
		if ((*head_a)->data <= arr[start])
		{
			// printf("push ssss\n");
			push(head_a, head_b);
			// printf("befor start [%d],,,,end [%d] \n", start, end);
			rotate(head_b, 'b');
			// rotate_stack_b(head_b);
			update_range(&start, &end, size);
			// printf("after start [%d],,,,end [%d] \n", start, end);
		}
		else if ((*head_a)->data <= arr[end])
		{
			push(head_a, head_b);
			if ((*head_b) && (*head_b)->next && (*head_b)->data < (*head_b)->next->data)
				swap(*head_b, 98);
			// printf("befor start [%d],,,,end [%d] \n", start, end);
			update_range(&start, &end, size);
			// printf("after start [%d],,,,end [%d] \n", start, end);

		}
		else
			rotate(head_a, 'a');
	}
	
}

int	max_index(list *head)
{
	int max = head->data;
	int i = 0;
	int i_max = 0;

	while (head)
	{
		if (head->data > max)
		{
			max = head->data;
			i_max = i;
		}
		head = head->next;
		i++;
	}
	return (i_max);
}

void push_to_a(list **head_a, list **head_b)
{
	while (*head_b)
	{
		if (max_index(*head_b) > (ft_lstsize(*head_b) / 2))
			while (max_index(*head_b) != 0)
				reverse(head_b, 'b');
		else
			while (max_index(*head_b) != 0)
				rotate(head_b, 'b');
		push_b(head_b, head_a);
	}
}

void	big_sort(list **head_a, list **head_b)
{
	list *tmp;
	int *arr;
	int size_head;
	int i;
	int range;

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
	bubble_sort(arr, size_head);
	range = find_range(size_head);
	pushing_to_b(head_a, head_b, arr, range, size_head);
	push_to_a(head_a, head_b);	
}
