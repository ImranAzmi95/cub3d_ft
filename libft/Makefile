# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iazmi <iazmi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 16:35:02 by iazmi             #+#    #+#              #
#    Updated: 2024/11/13 19:56:41 by iazmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
C_FLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES =	ft_atoi 					\
			ft_bzero					\
			ft_calloc 					\
			ft_isalnum 					\
			ft_isalpha 					\
			ft_isascii 					\
			ft_isdigit 					\
			ft_isprint 					\
			ft_itoa 					\
			ft_memchr 					\
			ft_memcmp 					\
			ft_memcpy 					\
			ft_memmove 					\
			ft_memset 					\
			ft_putchar_fd 				\
			ft_putendl_fd				\
			ft_putnbr_fd				\
			ft_putstr_fd				\
			ft_split					\
			ft_strchr 					\
			ft_strdup					\
			ft_striteri					\
			ft_strjoin					\
			ft_strlcat					\
			ft_strlcpy 					\
			ft_strlen 					\
			ft_strmapi 					\
			ft_strncmp 					\
			ft_strnstr 					\
			ft_strrchr 					\
			ft_strtrim					\
			ft_substr					\
			ft_tolower					\
			ft_toupper 					\
			ft_lstnew 					\
			ft_lstadd_front 			\
			ft_lstsize 					\
			ft_lstlast 					\
			ft_lstadd_back 				\
			ft_lstdelone 				\
			ft_lstclear 				\
			ft_lstiter 					\
			ft_lstmap 					\

GNL_SRC_FILES = 	get_next_line		\
					get_next_line_utils	\

PRINTF_SRC_FILES = 	ft_printf			\
					ft_printf_utils		\
					ft_fspec			\

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES) $(GNL_SRC_FILES) $(PRINTF_SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES) $(GNL_SRC_FILES) $(PRINTF_SRC_FILES)))

INCLUDE = include

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re