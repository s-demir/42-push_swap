NAME				= push_swap
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= sources/
OBJ_DIR				= obj/
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

FILES				= commands/push.c \
					  commands/rev_rotate.c \
					  commands/rotate.c \
					  commands/swap.c \
					  push_swap/handle_errors.c \
					  push_swap/init_a_to_b.c \
					  push_swap/init_b_to_a.c \
					  push_swap/push_swap.c \
					  push_swap/sort_stacks.c \
					  push_swap/sort_three.c \
					  push_swap/stack_init.c \
					  push_swap/stack_utils.c

OBJ					= $(FILES:%.c=$(OBJ_DIR)/%.o)

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
					@make -C ./libft

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			all clean fclean re
