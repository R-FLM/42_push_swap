# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 10:39:58 by flomulle          #+#    #+#              #
#    Updated: 2025/12/14 19:54:40 by flomulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	CONFIG
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME_DIR = ./lib
NAME = $(addprefix $(NAME_DIR)/, libft.a)
#	INCLUDE
INC_DIR = inc
#	SOURCES
SRC_DIR = src
SRC =	ft_isalpha.c ft_isdigit.c ft_isint.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c ft_tolower.c \
		\
		ft_strlen.c ft_atoi.c ft_atol.c\
		ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_strnstr.c \
		ft_strchr.c ft_strrchr.c \
		ft_bzero.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_itoa.c \
		ft_count_words.c ft_split.c ft_free_array_strs.c \
		ft_strmapi.c ft_striteri.c \
		\
		ft_calloc.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_memchr.c ft_memcmp.c \
		\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c \
		\
		ft_printf.c \
		ft_printf_parsing.c \
		ft_printf_specifiers0.c ft_printf_specifiers1.c \
		ft_printf_specifiers2.c ft_printf_specifiers3.c \
		ft_printf_settings.c \
		ft_printf_output1.c ft_printf_output2.c \
		ft_printf_utilities1.c ft_printf_utilities2.c \
		\
		ft_get_next_line.c ft_get_next_line_utils.c \
		\
		ft_abs.c ft_min.c ft_max.c
#	OBJECTS GEN
OBJ_DIR = ./build
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#	RULES
all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p $(NAME_DIR)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME_DIR)

re: fclean all

.PHONY: all clean fclean re
