# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 14:43:16 by kesaitou          #+#    #+#              #
#    Updated: 2025/11/04 16:20:58 by kesaitou         ###   ########.fr        #
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


MAND_SRCS = op_stack.c ring.c main.c operations.c parse.c sort.c parse_utils.c algo_lisdp.c
MAND_OBJS = $(SRCS:.c=.o)

BONUS_SRCS = checker.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

bonus : $(BONUS)
	
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME):$(MAND_OBJS) $(LIBFT)
	$(CC) $(MAND_SRCS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(BONUS): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(BONUS_SRCS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	
%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(MAND_OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re