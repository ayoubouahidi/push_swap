/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:42:14 by ayouahid          #+#    #+#             */
/*   Updated: 2025/01/18 12:42:16 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push.h"

// strchr
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (!(char)c)
		return ((char *)&str[i]);
	return (NULL);
}


// strjoin
size_t	ft_strlen(const char *a)
{
	int	i;

	i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return (i);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*s;
	size_t	i;

	s = (char *)src;
	i = 0;
	if (size == 0)
	{
		return (ft_strlen(s));
	}
	else
	{
		while (s[i] != '\0' && i < size - 1)
		{
			dest[i] = s[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (ft_strlen(s));
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;
	size_t	ret;

	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	ret = lendest + lensrc;
	i = 0;
	if (lendest >= size)
		return (lensrc + size);
	while (src[i] != '\0' && (lendest + 1) < size)
	{
		dest[lendest] = src[i];
		i++;
		lendest++;
	}
	dest[lendest] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (lens1 + lens2) + 1);
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s1, lens1 + 1);
	ft_strlcat(newstr, s2, lens2 + lens1 + 1);
	return (newstr);
}

// atoi
static int	fornotminette(int result, int cmpt, int cmpmoins)
{
	if (cmpt > 1)
		return (0);
	if (cmpmoins == 1)
		return (result * -1);
	return (result);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		cmpt;
	long	result;
	int		cmpmoins;

	cmpmoins = 0;
	result = 0;
	cmpt = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32 && str[i] != '\0'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		cmpt++;
		if (str[i] == '-')
			cmpmoins++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	result = fornotminette(result, cmpt, cmpmoins);
	return (result);
}
// is digit
int	ft_isdigit(int a)
{
	if ((a >= 48 && a <= 57))
	{
		return (1);
	}
	return (0);
}

// char *pile(int ac, char **av)
// {
// 	int i;
// 	char *newtab;
// 	newtab = malloc(1);
// 	newtab[0] = '\0';

// 	i = 1;
// 	if (ac >= 2)
// 	{
// 		while (i < ac)
// 		{
// 			if (av)
// 				return NULL;	
// 			char *temp0 = ft_strjoin(newtab, av[i]);
//             if (temp0 == NULL) {
//                 free(newtab);
//                 return NULL;
//             }
//             free(newtab); 
//             newtab = temp0;

// 			char *temp = ft_strjoin(newtab, " ");
//             if (temp == NULL) {
//                 free(newtab);
//                 return NULL;
//             }
//             free(newtab); 
//             newtab = temp;

// 			i++;
// 		}
// 		return(newtab);
// 	}
// }

// int	main(int ac, char **av)
// {
// 	char *pile_usr;

// 	pile_usr = pile(ac, av);
// 	// iterer dans le tableau
// 	printf("%s\n", pile_usr);
// }

void	printlist(list *head)
{
	list	*tmp;
	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int check(char *av)
{
	// int i;

	// i = 0;
	// while (av[i] != '\0')
	// {
	// 	if (ft_isdigit(av[i]))

	// }
	
}

list	*stock_arg(int ac, char **av)
{
	list *head;
	int	i;
	int j;
	list *new;
	char **str_arg;

	i = 1;
	head = NULL;
	if (ac >= 2)
	{	
		while(av[i])
		{
			if(av[i][0] == '\0')
				return (NULL);
			j = 0;
			// free(new);
			while (av[i][j])
			{
				// printf("%c\n", av[i][j]);
				if (!ft_isdigit(av[i][j]) && av[i][j] != 32)
				{
					return (NULL);
				}
				j++;
			}
			if (ft_strchr(av[i], 32))
			{
				j = 0;
				str_arg = ft_split(av[i], 32);
				while (str_arg[j])
				{
					new = ft_newnode(ft_atoi(str_arg[j]));
					ft_lstadd_back(&head, new);
					j++;
				}
			}
			else
			{
				new = ft_newnode(ft_atoi(av[i]));
				ft_lstadd_back(&head, new);
			}
			i++;
		}
		return(head);
	}
} 

int	main(int ac, char **av)
{
	list	*head;
	head = stock_arg(ac , av);
	printlist(head);

}
