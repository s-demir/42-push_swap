# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sedemir <sedemir@student.42kocaeli.com.tr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/24 19:00:00 by sedemir          #+#    #+#              #
#    Updated: 2026/11/24 19:00:00 by sedemir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BONUS	= checker
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC_DIR	= src
BON_DIR	= bonus

SRCS	= $(SRC_DIR)/push_swap.c \
		  $(SRC_DIR)/ft_utils.c \
		  $(SRC_DIR)/ft_split.c \
		  $(SRC_DIR)/stack_utils.c \
		  $(SRC_DIR)/stack_utils2.c \
		  $(SRC_DIR)/operations.c \
		  $(SRC_DIR)/operations2.c \
		  $(SRC_DIR)/operations3.c \
		  $(SRC_DIR)/parse.c \
		  $(SRC_DIR)/sort_small.c \
		  $(SRC_DIR)/sort_large.c \
		  $(SRC_DIR)/sort_large_utils.c \
		  $(SRC_DIR)/sort_large_utils2.c

BSRCS	= $(BON_DIR)/checker.c \
		  $(BON_DIR)/checker_ops.c \
		  $(BON_DIR)/get_next_line.c \
		  $(SRC_DIR)/ft_utils.c \
		  $(SRC_DIR)/ft_split.c \
		  $(SRC_DIR)/stack_utils.c \
		  $(SRC_DIR)/stack_utils2.c \
		  $(SRC_DIR)/operations.c \
		  $(SRC_DIR)/operations2.c \
		  $(SRC_DIR)/operations3.c \
		  $(SRC_DIR)/parse.c \
		  $(SRC_DIR)/sort_small.c \
		  $(SRC_DIR)/sort_large.c \
		  $(SRC_DIR)/sort_large_utils.c \
		  $(SRC_DIR)/sort_large_utils2.c

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.bo)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS)

$(BONUS): $(BOBJS)
	$(CC) $(CFLAGS) -o $(BONUS) $(BOBJS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(BON_DIR)/%.bo: $(BON_DIR)/%.c push_swap.h $(BON_DIR)/checker.h
	$(CC) $(CFLAGS) -I. -I$(BON_DIR) -c $< -o $@

$(SRC_DIR)/%.bo: $(SRC_DIR)/%.c push_swap.h
	$(CC) $(CFLAGS) -I. -I$(BON_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
