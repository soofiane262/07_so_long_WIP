# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 14:01:19 by sel-mars          #+#    #+#              #
#    Updated: 2021/11/10 14:24:54 by sel-mars         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

PGM		=	so_long.c

LIB		=	libso_long.a

HDFL	=	so_long.h

SRCS	=	so_long_ext00.c

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

AR		=	ar rc

CFLAGS	=	-Wall -Wextra -Werror 

$(NAME): $(OBJS) $(PGM) $(HDFL)
	@(cd libft/; make;)
	@(cd mlx/; make;)
	@$(CC) $(CFLAGS) -c $(SRCS) -I $(HDFL)
	@$(AR) $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(PGM) -L./mlx/ -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft -L. -lso_long -o $(NAME)

all:	$(NAME)

norm:
	@norminette $(PGM) $(SRCS) $(HDFL)

clean:
	@(cd libft/; make clean;)
	@(cd mlx/; make clean;)
	@/bin/rm -f $(OBJS)

fclean:	clean
	@(cd libft/; make fclean;)
	@/bin/rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
