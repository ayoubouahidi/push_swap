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


//-------------parse functions-------------//
char	**ft_split(char const *s, char c);



#endif