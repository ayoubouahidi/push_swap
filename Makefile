# SRC = linked.c ft_split.c push_swap.c
# CC = cc
# OBJS = $(SRC:.c=.o)
# CFLAGS = -Wall -Wextra -Werror
# NAME = push_swap
# L_CRT = ar rcs
# MK = make


# all :$(NAME)
# $(NAME): $(OBJS)
# 		$(MK) -C ./ft_printf
# 		$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a -o $(NAME)
# clean :
# 	rm -f $(OBJS)
	
# fclean : clean
# 	rm -f $(NAME)

# re : fclean all

# .PHONY : all bonus re fclean clean

# Variables
SRC		= linked.c ft_split.c push_swap.c swap.c push.c rotate.c reverse.c sorting_1.c big_sort.c
CC		= cc
OBJS	= $(SRC:.c=.o)
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= push_swap
L_CRT	= ar rcs
MK		= make

# Paths
FT_PRINTF_DIR	= ./ft_printf
FT_PRINTF_LIB	= $(FT_PRINTF_DIR)/libftprintf.a

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(MK) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re