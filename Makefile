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
FILENAMES			+= exec_utils handle_heredoc read_input

OBJ_FILES			= $(patsubst %, $(OBJ_DIR)/%.o, $(FILENAMES))
MAIN				= $(NAME).c

all:				$(NAME)

required:			compile_message $(OBJ_DIR) $(OBJ_FILES) libft

$(NAME):			required
					$(CC) -g $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(NAME)
					echo $(DONE_MSG)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
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

re:					fclean all

compile_message:
					echo $(COMPILING_MSG)

.PHONY:	all libft run clean fclean re re_bonus
