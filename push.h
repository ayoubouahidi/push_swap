#ifndef PUSH_H
# define PUSH_H

#include "./ft_printf/ft_printf.h"
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
void	sort_two_numbers(int *a, int *b);
void	sort_tree_numbers(int *a, int *b, int *c);

#endif