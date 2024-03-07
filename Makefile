# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsims <gsims@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 11:36:48 by georgesims        #+#    #+#              #
#    Updated: 2024/03/07 09:45:20 by gsims            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
UTILS = listutils
PARSING = parsing
MAIN = main init
LIBFT = ./libft/libft.a

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(UTILS)))\
	$(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(PARSING)))\
	$(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(MAIN)))\

# Convert source file names to object file names in the OBJ_DIR directory
OBJ_DIR = obj
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rule to build the executable: depends on object directory, object files, and the LIBFT library
# Compiles the object files and LIBFT library into the executable, linking with readline library
all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./libft  -lft -lreadline -o $(NAME)

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

# Generic rule to compile .c files into .o files, placing them in the object directory
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) -c $(CFLAGS) -c $< -o $@ $(LINK)
# $< is the name of the prerequisite (the .c file), and $@ is the name of the target (the .o file)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJS)
    
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
