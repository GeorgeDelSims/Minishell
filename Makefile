# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsims <gsims@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 11:36:48 by georgesims        #+#    #+#              #
#    Updated: 2024/03/18 12:16:04 by gsims            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc 
CFLAGS = -Wall -Wextra -Werror

CHECKER = check
UTILS = listutils listutils2 error utils free print_utils
PARSING = parsing parsing_tokens parsing_tokens2 env_parsing
MAIN = main init exec init_types

LIBFT = ./libft/libft.a
READLINE_DIR = $(HOME)/.brew/opt/readline/include
READLINE_LIB = $(HOME)/.brew/opt/readline/lib

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(UTILS)))\
	$(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(PARSING)))\
	$(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(MAIN)))\
	$(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(CHECKER)))\

# Convert source file names to object file names in the OBJ_DIR directory
OBJ_DIR = obj
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rule to build the executable: depends on object directory, object files, and the LIBFT library
# Compiles the object files and LIBFT library into the executable, linking with readline library
all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./libft -L$(READLINE_LIB) -lft -lreadline -o $(NAME)

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

# Generic rule to compile .c files into .o files, placing them in the object directory
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) -c $(CFLAGS) -I$(READLINE_DIR) -c $< -o $@ $(LINK)
# $< is the name of the prerequisite (the .c file), and $@ is the name of the target (the .o file)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJS)
    
fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
