#ifndef PUSH_H
# define PUSH_H

#include <stdlib.h>
#include <stdio.h>

#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

typedef struct list
{
	int			data;
	struct list	*next;

}	list;

//--------------linked lists functions ----------//
list	*ft_newnode(int	data);
void	ft_lstadd_back(list **lst, list *new);
int		ft_lstsize(list *lst);
void	ft_lstadd_front(list **lst, list *new);
list	*ft_lstlast(list *lst);
void	printlist(list *head);
//-------------parse functions-------------//
char	**ft_split(char const *s, char c);

//-------------swaping functions-------------//
void	swap(list *head, char type);
void	swap_ab(list *head_a, list *head_b);

//-------------push functions-------------//
void	push(list **head_a, list **head_b);
void	push_b(list **head_b, list **head_a);

//-------------rotation functions-------------//
void	rotate(list **head, char t);
void	rotate_ab(list **head_a, list **head_b);
//-------------reverse functions-------------//
void	reverse(list **head, char t);
void	reverse_ab(list **head_a, list **head_b);

//-------------sorting functions-------------//
void	sort_two_numbers(list **head);
void	sort_tree_numbers(list **head);
void	sort_four_numbers(list **head_a, list **head_b);
// void	sort_five_numbers(list **head_a, list **head_b);
void	sort_five_numbers(list **head_a, list **head_b);
void	big_sort(list **head_a, list **head_b);
int	check_if_sorted(list **head_a);


// big sorts function to help
void	swap_bubble(int *a, int *b);
void	swap_bubble2(list **a);
void	bubble_sort(int *arr,int size);
int	check_if_in_range(int head_data, int start , int range,int *arr);
int	check_if_in(int head_data, int start, int *arr);
int	find_range(int size);
void	update_range(int *start, int *end, int size);
int get_index(int value, int *arr, int size);
void	pushing_to_b(list **head_a, list **head_b, int *arr, int end, int size);
int	max_index(list *head);
void push_to_a(list **head_a, list **head_b);


#endif
