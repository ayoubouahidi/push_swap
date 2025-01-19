#ifndef PUSH_H
# define PUSH_H

typedef struct list
{
	int			data;
	struct list	*next;

}	list;

list	*ft_newnode(int	data);
void	ft_lstadd_back(list **lst, list *new);
char	**ft_split(char const *s, char c);

#endif