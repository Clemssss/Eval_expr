# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clementg <clementg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/18 01:09:57 by clementg          #+#    #+#              #
#    Updated: 2018/08/18 01:32:35 by clementgirard    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	eval_expr

CC			=	gcc
CFLAGS	=	-Wall -Wextra -Werror

_SRCS	=	main.c					\
				eval_expr.c			\
				calc.c					\
				functions.c			\
				pile_op.c				\
				pile_calc.c

HEADER_DIR	=	includes

DIR	=	srcs

SRCS	=	$(addprefix $(DIR)/, $(_SRCS))

OBJS	=	$(SRCS:.c=.o)

#COLORS
_CYAN=\x1b[36m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_END=\x1b[0m

all:	$(NAME)

$(NAME)	:	$(OBJS)
					@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(DIR)
					@echo "$(NAME) : $(_GREEN)Done$(_END)"

%.o : %.c
					@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

clean	:
					@/bin/rm -f $(OBJS)
					@echo "$(NAME) clean : $(_GREEN)Done$(_END)"

fclean	:	clean
					@/bin/rm -f $(NAME)
					@echo "$(NAME) fclean : $(_GREEN)Done$(_END)"

re			:	fclean all

.PHONY	:	all clean fclean re
