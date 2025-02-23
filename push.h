/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:27:53 by ayouahid          #+#    #+#             */
/*   Updated: 2025/02/22 22:27:55 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdlib.h>
# include <stdio.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

//--------------linked lists functions ----------//
t_list	*ft_newnode(int data);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	printlist(t_list *head);
void	ft_lstclear(t_list **lst);
//-------------parse functions-------------//
char	**ft_split(char const *s, char c);

//-------------swaping functions-------------//
void	swap(t_list *head, char type);
void	swap_ab(t_list *head_a, t_list *head_b);

//-------------push functions-------------//
void	push(t_list **head_a, t_list **head_b);
void	push_b(t_list **head_b, t_list **head_a);

//-------------rotation functions-------------//
void	rotate(t_list **head, char t);
void	rotate_ab(t_list **head_a, t_list **head_b);
//-------------reverse functions-------------//
void	reverse(t_list **head, char t);
void	reverse_ab(t_list **head_a, t_list **head_b);

//-------------sorting functions-------------//
void	sort_two_numbers(t_list **head);
void	sort_tree_numbers(t_list **head);
void	sort_four_numbers(t_list **head_a, t_list **head_b);
// void	sort_five_numbers(t_list **head_a, t_list **head_b);
void	sort_five_numbers(t_list **head_a, t_list **head_b);
void	big_sort(t_list **head_a, t_list **head_b);
int		check_if_sorted(t_list **head_a);

// big sorts function to help
void	swap_bubble(int *a, int *b);
void	swap_bubble2(t_list **a);
void	bubble_sort(int *arr, int size);
int		check_if_in_range(int head_data, int start, int range, int *arr);
int		check_if_in(int head_data, int start, int *arr);
int		find_range(int size);
void	update_range(int *start, int *end, int size);
int		get_index(int value, int *arr, int size);
void	pushing_to_b(t_list **head_a, t_list **head_b, int *arr, int end);
int		max_index(t_list *head);
void	push_to_a(t_list **head_a, t_list **head_b);
long	ft_atoi(const char *str);
long	ft_atoi_err(const char *str, int *err);
int		find_index(t_list	**head_a, int pt);

//main

void	free_split(char **str);
int		lenght(char *av);
char	*isvalid(char *av);
void	printlist(t_list *head);
int		check(t_list *head);
int		is_valid_arg(char *arg);

#endif
