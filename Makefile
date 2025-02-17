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
SRC		= linked.c ft_split.c push_swap.c swap.c push.c rotate.c reverse.c sorting_1.c big_sort.c big_sort_help1.c big_sort_help2.c
CC		= cc
OBJS	= $(SRC:.c=.o)
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= push_swap
L_CRT	= ar rcs
MK		= make

# Paths
FT_PRINTF_DIR	= ./ft_printf
FT_PRINTF_LIB	= $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Rules
all: $(NAME)

# $(NAME): $(OBJS)
# 	$(MK) -C $(FT_PRINTF_DIR)
# 	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) -o $(NAME)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)


$(NAME): $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME)

$(FT_PRINTF_LIB):
	$(MK) -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	$(MK) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MK) -C $(FT_PRINTF_DIR) clean
	$(MK) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MK) -C $(FT_PRINTF_DIR) fclean
	$(MK) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re