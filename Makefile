# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:38:23 by abollen           #+#    #+#              #
#    Updated: 2022/02/04 14:00:57 by abollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***** VARIABLES *****#

PROJECT = push_swap
BONUS = ./checker
NAME = ./push_swap
HEADER = includes/push_swap.h

FILES = push_swap.c index.c check.c op_rotate.c op_push.c op_swap.c op_reverse.c autorotate.c sort.c insert.c utils.c multirotate.c
OBJ = ${addprefix ${OBJ_DIR}/,${FILES:.c=.o}}

BONUS_FILES = index.c check.c op_rotate.c op_push.c op_swap.c op_reverse.c autorotate.c sort.c insert.c multirotate.c utils.c checker.c
BONUS_OBJ = ${addprefix ${OBJ_DIR}/,${BONUS_FILES:.c=.o}}

SRC_DIR = src
OBJ_DIR = obj
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

#***** RULES *****#

all : libft ${OBJ_DIR} ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${HEADER} libft/libft.a
	@$(CC) $(CFLAGS) -Ilibft -c $< -o $@
	@echo "\033[36m[${PROJECT}]\033[92m[BUILD]\033[97m $@."

$(NAME): ${LIBFT} ${OBJ_DIR} $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) -Llibft -lft 
	@echo "\033[36m[${PROJECT}]\033[92m[BUILD] \033[0m${NAME}"

${BONUS}: ${LIBFT} ${OBJ_DIR} ${BONUS_OBJ}
	@$(CC) $(BONUS_OBJ) -o $(BONUS) -Llibft -lft 
	@echo "\033[36m[${PROJECT}]\033[92m[BUILD] \033[0m${BONUS}"

bonus: ${BONUS}

${OBJ_DIR}:
	@mkdir obj
	@echo "\033[36m[${PROJECT}]\033[92m[BUILD] \033[0m${OBJ_DIR} folder"

${LIBFT}:
	@make -C libft

libft:
	@make -C libft

clean :
	@rm -rf ${OBJ_DIR}
	@echo "\033[36m[${PROJECT}]\033[93m[CLEAN] \033[0m${OBJ_DIR} folder"
	@make -C libft clean

fclean : clean
	@make -C libft extfclean
	@rm -rf ${NAME}
	@rm -rf ${BONUS}
	@echo "\033[36m[${PROJECT}] \033[93m[CLEAN] \033[0m${NAME}"
	@echo "\033[36m[${PROJECT}] \033[93m[CLEAN] \033[0m${BONUS}"

re: fclean all

.PHONY : all clean fclean re libft