# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 11:36:48 by georgesims        #+#    #+#              #
#    Updated: 2024/03/06 12:10:51 by georgesims       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTILS = lstutils utils
PARSING = parsing

SRCS_DIR = srcs
# Correct the use of curly braces for variable reference
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(UTILS)))\
	$(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(PARSING)))\

OBJ_DIR = obj
# Convert source file names to object file names in the OBJ_DIR directory
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# Rule to build the executable: depends on object directory, object files, and the LIBFT library
# Compiles the object files and LIBFT library into the executable, linking with readline library
$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

# Generic rule to compile .c files into .o files, placing them in the object directory
# $< is the name of the prerequisite (the .c file), and $@ is the name of the target (the .o file)
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LINK)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ_DIR)
	$(RM) $(OBJS)
    
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
