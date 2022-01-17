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

NAME	=	libft.a

HDFL	=	libft.h

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\

OBJS	=	$(SRCS:%.c=%.o)

GNLSRCS	=	get_next_line.c get_next_line_utils.c

GNLOBJS	=	$(GNLSRCS:%.c=%.o)

BNSSRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BNSOBJS	=	$(BNSSRCS:%.c=%.o)

GNLBNSSCRS	=	get_next_line_bonus.c get_next_line_utils_bonus.c

GNLBNSOBJS	=	$(GNLBNSSCRS:%.c=%.o)

CC		=	gcc

AR		=	ar rc

CFLAGS	=	-Wall -Wextra -Werror 

$(NAME): $(OBJS) $(GNLOBJS)
	@$(CC) $(CFLAGS) -c $(SRCS) -I libft.h
	@$(CC) $(CFLAGS) -c $(GNLSRCS) -I get_next_line.h
	@$(AR) $(NAME) $(OBJS) $(GNLOBJS)

all:	$(NAME) bonus

bonus: $(OBJS) $(BNSOBJS) $(GNLOBJS) $(GNLBNSOBJS)
	@$(CC) $(CFLAGS) -c $(SRCS) $(BNSSRCS) -I libft.h
	@$(CC) $(CFLAGS) -c $(GNLSRCS) -I get_next_line.h
	@$(CC) $(CFLAGS) -c $(GNLBNSSCRS) -I get_next_line_bonus.h
	@$(AR) $(NAME) $(OBJS) $(BNSOBJS) $(GNLOBJS) $(GNLBNSOBJS)

clean:
	@/bin/rm -f $(OBJS) $(BNSOBJS)

fclean:	clean
	@/bin/rm -f $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re
