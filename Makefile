# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 14:43:16 by kesaitou          #+#    #+#              #
#    Updated: 2025/11/04 03:39:56 by kesaitou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

LIBDIR = $(LIBFTDIR)
LDFLAGS = -L $(LIBDIR)
LDLIBS = -lft


SRCS = op_stack.c ring.c main.c operations.c parse.c sort.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re