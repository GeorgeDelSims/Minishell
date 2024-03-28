# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsims <gsims@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 11:36:48 by georgesims        #+#    #+#              #
#    Updated: 2024/03/28 13:13:09 by gsims            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc 
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

CHECKER = check
UTILS = listutils listutils2 error free print_utils utils
PARSING = parsing parsing_tokens parsing_tokens_append parsing_utils unclosed_quotes
ENV = env env_parsing
MAIN = main init exec init_types here_doc update_list pipe
BUILTINS = pwd cd export echo env unset

LIBFT = ./libft/libft.a
READLINE_DIR = $(HOME)/.brew/opt/readline/include
READLINE_LIB = $(HOME)/.brew/opt/readline/lib

PARSING_DIR = parsing
ENV_DIR = env
SRCS_DIR = srcs
BUILTINS_DIR = builtins
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(UTILS)))\
	$(addprefix $(SRCS_DIR)/$(PARSING_DIR)/, $(addsuffix .c, $(PARSING)))\
	$(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(MAIN)))\
	$(addprefix $(SRCS_DIR)/$(ENV_DIR)/, $(addsuffix .c, $(ENV)))\
	$(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(CHECKER)))\
	$(addprefix $(SRCS_DIR)/$(BUILTINS_DIR)/, $(addsuffix .c, $(BUILTINS)))\

# Convert source file names to object file names in the OBJ_DIRS directory
OBJ_DIR = obj
OBJ_DIRS = $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(PARSING_DIR)) $(addprefix $(OBJ_DIR)/, $(ENV_DIR)) $(addprefix $(OBJ_DIR)/, $(BUILTINS_DIR))
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

# Ensures that obj directories are created before the obj files
$(OBJS): | $(OBJ_DIRS)

# Rule to build the executable: depends on object directory, object files, and the LIBFT library
# Compiles the object files and LIBFT library into the executable, linking with readline library

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJ_DIRS) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./libft -L$(READLINE_LIB) -lft -lreadline -o $(NAME)

$(OBJ_DIRS): 
	mkdir -p $@

# Generic rule to compile .c files into .o files, placing them in the object directory

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(READLINE_DIR) -c $< -o $@
	
# $< is the name of the prerequisite (the .c file), and $@ is the name of the target (the .o file)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ_DIRS)
	rm -rf $(OBJS)
    
fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
