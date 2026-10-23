# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 18:37:17 by flomulle          #+#    #+#              #
#    Updated: 2025/12/16 14:57:23 by flomulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Werror -Wall
RM = rm -rf
MAKE = make
NAME = push_swap
NAME_BONUS = checker
INC_DIR = ./inc
INC = -I$(INC_DIR)
INC_DIR_BONUS = ./inc_bonus
INC_BONUS = -I$(INC_DIR_BONUS)
INC_LFT_DIR = ./libft/inc
INC_LFT = -I$(INC_LFT_DIR)
LIBFT_DIR = ./libft
LIBFT = ./libft/lib/libft.a
SRC_DIR = ./src
SRC = 	push_swap.c push_swap_parsing.c \
		push_swap_sort.c push_swap_sort_small.c push_swap_sort_utils.c \
		push_swap_check.c \
		push_swap_push.c push_swap_swap.c \
		push_swap_rotate.c push_swap_rev_rotate.c \
		push_swap_utils.c
SRC_DIR_BONUS = ./src_bonus
SRC_BONUS = checker_bonus.c \
			push_swap_push_bonus.c push_swap_swap_bonus.c \
			push_swap_rotate_bonus.c push_swap_rev_rotate_bonus.c
OBJ_DIR = ./build
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR_BONUS = ./build_bonus
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:.c=.o))

all: $(LIBFT) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) $(INC_LFT) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(INC_LFT) $^ -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

bonus: all $(NAME_BONUS)

$(OBJ_DIR_BONUS):
	mkdir -p ./build_bonus

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INC) $(INC_BONUS) $(INC_LFT) -c $< -o $@

$(NAME_BONUS): $(OBJ) $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $(INC_BONUS) $(INC_LFT) $(filter-out $(OBJ_DIR)/push_swap.o, $(OBJ)) $(OBJ_BONUS) $(LIBFT) -o $@

test: bonus
	python3 test/push_swap_test.py

.PHONY: all clean fclean re bonus test
