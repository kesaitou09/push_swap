# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 14:43:16 by kesaitou          #+#    #+#              #
#    Updated: 2025/11/07 02:58:33 by kesaitou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra


LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

LIBDIR = $(LIBFTDIR)
LDFLAGS = -L $(LIBDIR)
LDLIBS = -lft


MAND_SRCS = do_best_rotate.c \
			ring.c \
			main.c \
			operation_rotate_one.c \
			operation_rotate_two.c \
			operation_push.c \
			operation_swap.c \
			parse.c sort.c \
			parse_utils.c \
			algo_lisdp.c \
			get_info_to.c \
			tark_utils.c \
			manage_sort.c \
			manage_insert.c \
			

MAND_OBJS = $(MAND_SRCS:.c=.o)

BONUS_SRCS = 	checker_main.c \
				checker_utils.c\
				ring.c \
				operation_push.c \
				operation_rotate_one.c\
				operation_rotate_two.c\
				operation_swap.c\
				parse.c \
				sort.c \
				parse_utils.c \
				algo_lisdp.c \


BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

bonus : $(BONUS)
	
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME):$(MAND_OBJS) $(LIBFT)
	$(CC) $(MAND_OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(BONUS): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(BONUS_OBJS) $(LDFLAGS) $(LDLIBS) -o $(BONUS)
	
%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(MAND_OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all


.PHONY: all clean fclean re