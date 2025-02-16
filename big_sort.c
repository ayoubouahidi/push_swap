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

int	find_range(int size)
{
	if(size > 5 && size <= 100)
		return (size / 5);
	else if (size > 100 && size <= 500)
		return (size / 12);
	else
		return (20);
}

// void	push_element_stack_b(list **head_a, list **head_b, int *arr, int range)
// {
// 	int start;

// 	start = 0;
// 	while ((*head_a))
// 	{
// 		if (check_if_in_range((*head_a)->data, start, range, arr))
// 		{
// 			push(head_a, head_b);
// 			// if (ft_lstsize(*head_b) != 1 && ((*head_b)->data < (*head_b)->next->data) )
// 			// {
// 			// 	swap_bubble(&(*head_b)->data, &(*head_b)->next->data);
// 			// }
// 			start++;
// 			range++;
// 		}
// 		else if (check_if_in((*head_a)->data, start, arr))
// 		{
// 			push(head_a, head_b);
// 			rotate(head_b , 'b');
// 			start++;
// 			range++;
// 		}
// 		else
// 			rotate(head_a, 'a');
// 		*head_a = (*head_a)->next;
// 		printf("im here ! ");
// 	}
// }

// void	pushing_to_b(list **head_a, list **head_b, int *arr, int range)
// {
// 	int start;
// 	list *tmp;

// 	tmp = *head_a;
// // head_b++;
// 	start = 0;
// 	while (tmp)
// 	{
// 		ft_printf("the head a data is %d\n", (tmp)->data);
// 		// ft_printf("a data is %d\n", (*head_a)->data);
// 		if (check_if_in_range((tmp)->data,start, range, arr))
// 		{
// 			push(&tmp, head_b);
// 			ft_printf("the head b data is %d\n", (*head_b)->data);
// 			start++;
// 			range++;
// 		}
// 		else
// 			rotate(&tmp, 'a');
// 		tmp = tmp->next;
// 	}
	
// }

void	update_range(int *start, int *end, int size)
{
	if (*start < *end - 1)
		(*start)++;
	if (*end < size - 1)
		(*end)++;
}


void	rotate_stack_a(list **a)
{
	list	*tmp;
	list	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_stack_b(list **b)
{
	list	*tmp;
	list	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
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

void	pushing_to_b(list **head_a, list **head_b, int *arr, int end, int size)
{
	int start;
	(void)arr;
	int size909 = ft_lstsize(*head_a);
	// tmp = *head_a;
	start = 0;
    // printlist(*head_a);
	while (*head_a)
	{
		// ft_printf("the head a data is %d\n", (*head_a)->data);
		// ft_printf("a data is %d\n", (*head_a)->data);
		if (get_index((*head_a)->data, arr, size909) <= ft_lstsize(*head_b))
		{
			push(head_a, head_b);
			// printf("befor start [%d],,,,end [%d] \n", start, end);
			rotate(head_b, 'b');
			// rotate_stack_b(head_b);
			update_range(&start, &end, size);
			// printf("after start [%d],,,,end [%d] \n", start, end);
		}
		else if (get_index((*head_a)->data, arr, size909) <= ft_lstsize(*head_b) + ft_lstsize(*head_a) / 10)
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
			
		// *head_a = (*head_a)->next;
	}
	// printlist(*head_b);
	
}

// void	pushing_to_b(list **head_a, list **head_b, int *arr, int end, int size)
// {
// 	int start;

// 	// tmp = *head_a;
// 	start = 0;
//     // printlist(*head_a);
// 	while (*head_a)
// 	{
// 		// ft_printf("the head a data is %d\n", (*head_a)->data);
// 		// ft_printf("a data is %d\n", (*head_a)->data);
// 		if ((*head_a)->data <= arr[start])
// 		{
// 			// printf("push ssss\n");
// 			push(head_a, head_b);
// 			// printf("befor start [%d],,,,end [%d] \n", start, end);
// 			rotate(head_b, 'b');
// 			// rotate_stack_b(head_b);
// 			update_range(&start, &end, size);
// 			// printf("after start [%d],,,,end [%d] \n", start, end);
// 		}
// 		else if ((*head_a)->data <= arr[end])
// 		{
// 			push(head_a, head_b);
// 			if ((*head_b) && (*head_b)->next && (*head_b)->data < (*head_b)->next->data)
// 				swap(*head_b, 98);
// 			// printf("befor start [%d],,,,end [%d] \n", start, end);
// 			update_range(&start, &end, size);
// 			// printf("after start [%d],,,,end [%d] \n", start, end);

// 		}
// 		else
// 			rotate(head_a, 'a');
// 		// *head_a = (*head_a)->next;
// 	}
// 	// printlist(*head_b);
	
// }

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
	// ft_printf("ther max is : %d\n the pos is %d\n", max, i_max);
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

	// head_b++;
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
	// ft_printf("the firt element is %d\n", *arr);
	bubble_sort(arr, size_head);
	range = find_range(size_head);
	pushing_to_b(head_a, head_b, arr, range, size_head);
	push_to_a(head_a, head_b);
	// printlist(*head_a);
	// ft_printf("the range is : %d\n", range);
	// push_element_stack_b(head_a, head_b, arr, range);
	// printing
	// i = 0;
	// while (i < size_head)
	// {
	// 	ft_printf("%d ", arr[i]);
	// 	i++;
	// }
	// ft_printf("\n");

	
	
}

// int main()
// {
// 	int arr[4] = {1 ,2 , 4, 6};
// 	int s = check_if_in_range(2, 0, 3,arr);
// 	printf("s is : %d\n", s);
// }
