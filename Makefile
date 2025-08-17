

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Program name
NAME = cub3d

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-O0 -g3 -fsanitize=address,leak,undefined
MAKEFLAGS += --no-print-directory

# OS name
UNAME_S := $(shell uname -s)

# OS-specific settings
ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -lXext -lX11 -lm -lz
	MLX_DIR = mlx_linux
else ifeq ($(UNAME_S), Darwin)
	MLX_FLAGS = -framework OpenGL -framework AppKit
	MLX_DIR = mlx
else
	$(error Unsupported operating system: $(UNAME_S))
endif

#------------------------------------------------------------------------------#
#                                   COLORS                                     #
#------------------------------------------------------------------------------#

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
CYAN = \033[96m
RESET = \033[0m

#------------------------------------------------------------------------------#
#                                 DIRECTORIES                                  #
#------------------------------------------------------------------------------#

SRC_DIR = src
OBJ_DIR = obj
BONUS_SRC_DIR = src_bonus
BONUS_OBJ_DIR = obj_bonus
LIBFT_DIR = libft
HEADERS_DIR = include
BONUS_HEADERS_DIR = include_bonus

#------------------------------------------------------------------------------#
#                                 LIBRARIES                                    #
#------------------------------------------------------------------------------#

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx $(MLX_FLAGS)

#------------------------------------------------------------------------------#
#                                  INCLUDES                                    #
#------------------------------------------------------------------------------#

INCLUDE_DIRS = $(shell find $(HEADERS_DIR) -type d)
BONUS_INCLUDE_DIRS = $(shell find $(BONUS_HEADERS_DIR) -type d)

INCLUDES = $(addprefix -I,$(INCLUDE_DIRS)) -I$(LIBFT_DIR)/include -I$(MLX_DIR)
BONUS_INCLUDES = $(addprefix -I,$(BONUS_INCLUDE_DIRS)) -I$(LIBFT_DIR)/include

#------------------------------------------------------------------------------#
#                                SOURCE FILES                                  #
#------------------------------------------------------------------------------#

SRC_FILES = ray_cast_init		\
			ray_cast_dda		\
			ray_cast_utils		\
			ray_cast			\
			texture_loader

SRC_FILES_TEAM = 	cub3d 				\
					parse 				\
					read_file_utils 	\
					read_file		 	\
				 	read_map			\
				 	read_map_helpers	\
				 	utils 				\
					colour_parse		\
					player_init			\
					player_movement		\

BONUS_SRC_FILES = \

#------------------------------------------------------------------------------#
#                               OBJECT FILES                                   #
#------------------------------------------------------------------------------#

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES) $(SRC_FILES_TEAM)))

BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR)/, $(addsuffix .o, $(BONUS_SRC_FILES)))

# Src paths for make
VPATH = $(SRC_DIR):$(wildcard $(BONUS_SRC_DIR)):$(shell find $(SRC_DIR) $(wildcard $(BONUS_SRC_DIR)) -type d 2>/dev/null | tr '\n' ':')

#------------------------------------------------------------------------------#
#                                  TESTING                                     #
#------------------------------------------------------------------------------#

TEST_NAME = tester
BONUS_TEST_NAME = btester
TEST_OBJ_DIR = test_obj
BONUS_TEST_OBJ_DIR = btest_obj
TEST_OBJ = $(TEST_OBJ_DIR)/$(TEST_NAME).o $(addprefix $(TEST_OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES) $(SRC_FILES_TEAM)))
BONUS_TEST_OBJ = $(BONUS_TEST_OBJ_DIR)/$(BONUS_TEST_NAME).o $(addprefix $(BONUS_TEST_OBJ_DIR)/, $(addsuffix .o, $(BONUS_SRC_FILES)))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@echo "$(NAME): $(GREEN)Object files created.$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS) && echo "$(NAME): $(GREEN)Program created.$(RESET)"

bonus: $(LIBFT) $(BONUS_OBJ)
	@echo "$(NAME) $(CYAN)(bonus)$(RESET): $(GREEN)Bonus object files created.$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME) $(LIBS) && echo "$(NAME) $(CYAN)(bonus)$(RESET): $(GREEN)Program created.$(RESET)"

#------------------------------------------------------------------------------#
#                               COMPILATION                                    #
#------------------------------------------------------------------------------#

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: %.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

#------------------------------------------------------------------------------#
#                                 LIBRARIES                                    #
#------------------------------------------------------------------------------#

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

#------------------------------------------------------------------------------#
#                                 CLEANING                                     #
#------------------------------------------------------------------------------#

clean:
	@rm -rf $(OBJ_DIR) && echo "$(NAME): $(RED)Object files deleted.$(RESET)"
	@if [ -d "$(BONUS_OBJ_DIR)" ]; then \
		rm -rf $(BONUS_OBJ_DIR) && echo "$(NAME): $(RED)Bonus object files deleted.$(RESET)"; \
	fi
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) && echo "$(NAME): $(RED)Program deleted.$(RESET)"
	@if [ -f "$(TEST_NAME)" ]; then \
		rm -f $(TEST_NAME) && echo "$(TEST_NAME): $(RED)Test program deleted.$(RESET)"; \
	fi
	@if [ -f "$(BONUS_TEST_NAME)" ]; then \
		rm -f $(BONUS_TEST_NAME) && echo "$(BONUS_TEST_NAME): $(RED)Bonus test program deleted.$(RESET)"; \
	fi
	@make fclean -C $(LIBFT_DIR)

re: fclean all

bre: fclean bonus

#------------------------------------------------------------------------------#
#                                  TESTING                                     #
#------------------------------------------------------------------------------#

test: $(LIBFT) $(TEST_OBJ)
	@$(CC) $(CFLAGS) $(TEST_OBJ) -o $(TEST_NAME) $(LIBS) && echo "$(TEST_NAME): $(YELLOW)Test program created.$(RESET)"

bonus_test: $(LIBFT) $(BONUS_TEST_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_TEST_OBJ) -o $(BONUS_TEST_NAME) $(LIBS) && echo "$(BONUS_TEST_NAME): $(YELLOW) Bonus test program created.$(RESET)"

$(TEST_OBJ_DIR)/%.o: %.c
	@mkdir -p $(TEST_OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_TEST_OBJ_DIR)/%.o: %.c
	@mkdir -p $(BONUS_TEST_OBJ_DIR)
	@$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

tclean:
	@if [ -d "$(TEST_OBJ_DIR)" ]; then \
		rm -rf $(TEST_OBJ_DIR) && echo "$(TEST_NAME): $(RED)Test object files deleted.$(RESET)"; \
	fi
	@if [ -d "$(BONUS_TEST_OBJ_DIR)" ]; then \
		rm -rf $(BONUS_TEST_OBJ_DIR) && echo "$(BONUS_TEST_NAME): $(RED)Bonus test object files deleted.$(RESET)"; \
	fi
	@if [ -f "$(TEST_NAME)" ]; then \
		rm -f $(TEST_NAME) && echo "$(TEST_NAME): $(RED)Test program deleted.$(RESET)"; \
	fi
	@if [ -f "$(BONUS_TEST_NAME)" ]; then \
		rm -f $(BONUS_TEST_NAME) && echo "$(BONUS_TEST_NAME): $(RED)Bonus test program deleted.$(RESET)"; \
	fi
	@make fclean -C $(LIBFT_DIR)

tre: tclean test

#------------------------------------------------------------------------------#
#                                 PHONY                                        #
#------------------------------------------------------------------------------#

.PHONY: all bonus clean fclean re bre test bonus_test tclean tre
