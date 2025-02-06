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
int	ft_lstsize(list *lst);
void	ft_lstadd_front(list **lst, list *new);

//-------------parse functions-------------//
char	**ft_split(char const *s, char c);

//-------------swaping functions-------------//
void	swap(list *head, char type);
void	swap_ab(list *head_a, list *head_b);

//-------------push functions-------------//
void	push(list **head_a, list **head_b);
void	push_b(list **head_b, list **head_a);

#endif