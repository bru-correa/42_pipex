ifndef VERBOSE
.SILENT:
endif

RED					= \033[1;31m
YELLOW				= \033[1;33m
GREEN				= \033[1;32m
NOCOLOR				= \033[0m
DONE_MSG			= "$(GREEN)Done!$(NOCOLOR)"
COMPILING_MSG		= "$(YELLOW)Compiling...$(NOCOLOR)"
CLEANING_MSG		= "$(RED)Cleaning up...$(NOCOLOR)"

NAME				= pipex
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror $(INCLUDE)
CFLAGS_LIB			= $(CFLAGS_LIBFT)
CFLAGS_LIBFT		= -L $(LIBFT_DIR) -lft
INCLUDE				= -I $(INCLUDE_DIR) -I $(LIBFT_DIR)

INCLUDE_DIR			= ./include
SRC_DIR				= ./src
OBJ_DIR				= ./obj
LIB_DIR				= ./lib

LIBFT_DIR			= $(LIB_DIR)/libft

FILENAMES			= exit_error exec get_cmd_path parser parser_utils
FILENAMES			+= exec_utils

OBJ_FILES			= $(patsubst %, $(OBJ_DIR)/%.o, $(FILENAMES))
MAIN				= $(NAME).c

# BONUS
FILENAMES_BONUS		= $(addsuffix _bonus, $(FILENAMES))
FILENAMES_BONUS		+= handle_heredoc_bonus read_input_bonus

OBJ_BONUS_FILES		= $(patsubst %, $(OBJ_DIR)/%.o, $(FILENAMES_BONUS))
MAIN_BONUS			= $(NAME)_bonus.c
SRC_BONUS_DIR		= ./src_bonus

all:				$(NAME)

bonus:				required_bonus
					$(CC) -g $(MAIN_BONUS) $(OBJ_BONUS_FILES) $(CFLAGS) \
						$(CFLAGS_LIB) -o $(NAME)_bonus
					echo $(DONE_MSG)

required:			compile_message $(OBJ_DIR) $(OBJ_FILES) libft

required_bonus:		compile_message $(OBJ_DIR) $(OBJ_BONUS_FILES) libft

$(NAME):			required
					$(CC) -g $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(NAME)
					echo $(DONE_MSG)

$(OBJ_DIR):
					mkdir -p $@

# MANDATORY
$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) -c -g $< $(CFLAGS) -o $@

# BONUS
$(OBJ_DIR)/%.o:		$(SRC_BONUS_DIR)/%.c
					$(CC) -c -g $< $(CFLAGS) -o $@

libft:
					$(MAKE) -C $(LIBFT_DIR)

clean:
					echo $(CLEANING_MSG)
					$(MAKE) -C $(LIBFT_DIR) clean
					rm -rf $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_DIR) fclean
					rm -f $(NAME)
					rm -f $(NAME)_bonus

re:					fclean all

re_bonus:			fclean bonus

compile_message:
					echo $(COMPILING_MSG)

.PHONY:	all libft run clean fclean re re_bonus
