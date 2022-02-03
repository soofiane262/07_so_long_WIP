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

CC		=	gcc

AR		=	ar rc

CFLAGS	=	-Wall -Wextra -Werror 

PGM		=	assets/mndt/so_long.c

LIB		=	libso_long.a

HDFL	=	assets/mndt/so_long.h

SRCS	=	assets/mndt/so_long_ext00.c assets/mndt/so_long_ext01.c assets/mndt/so_long_ext02.c\
			assets/mndt/so_long_ext03.c assets/mndt/so_long_ext04.c assets/mndt/so_long_ext05.c\
			assets/mndt/so_long_ext06.c assets/mndt/so_long_ext07.c

OBJS	=	$(SRCS:%.c=%.o)

BNSPGM	=	assets/bns/so_long_bonus.c

BNSLIB	=	libso_long_bonus.a

BNSHDFL	=	assets/bns/so_long_bonus.h

BNSSRCS	=	assets/bns/so_long_ext00_bonus.c assets/bns/so_long_ext01_bonus.c assets/bns/so_long_ext02_bonus.c\
			assets/bns/so_long_ext03_bonus.c assets/bns/so_long_ext04_bonus.c assets/bns/so_long_ext05_bonus.c\
			assets/bns/so_long_ext06_bonus.c assets/bns/so_long_ext07_bonus.c assets/bns/so_long_ext08_bonus.c\
			assets/bns/so_long_ext09_bonus.c assets/bns/so_long_ext10_bonus.c

BNSOBJS	=	$(BNSSRCS:%.c=%.o)

$(NAME): $(OBJS) $(PGM) $(HDFL)
	@(cd libft/; make;)
	@(cd mlx/; make;)
	@$(AR) $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(PGM) -L./mlx -lmlx -framework OpenGL -framework AppKit -L./libft -lft -L. -lso_long -o $(NAME)

all:	$(NAME) bonus

bonus: $(BNSOBJS) $(BNSPGM) $(BNSHDFL)
	@(cd libft/; make;)
	@(cd mlx/; make;)
	@$(AR) $(BNSLIB) $(BNSOBJS)
	@$(CC) $(CFLAGS) $(BNSPGM) -L./mlx -lmlx -framework OpenGL -framework AppKit -L./libft -lft -L. -lso_long_bonus -o so_long_bonus

norm:
	@norminette $(PGM) $(SRCS) $(HDFL) $(BNSPGM) $(BNSSRCS) $(BNSHDFL) libft/

clean:
	@(cd libft/; make clean;)
	@(cd mlx/; make clean;)
	@/bin/rm -f $(OBJS) $(BNSOBJS)

fclean:	clean
	@(cd libft/; make fclean;)
	@/bin/rm -f $(NAME) $(LIB) $(BNSLIB) so_long_bonus

re:	fclean all

.PHONY:	all bonus norm clean fclean re
