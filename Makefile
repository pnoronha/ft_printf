# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 15:33:48 by pnoronha          #+#    #+#              #
#    Updated: 2021/06/17 15:33:48 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT		=	libft/libft.a

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

SRCS	=	$(wildcard sources/*.c)

OBJS	:=	$(patsubst sources/%.c, objects/%.o, $(SRCS))

$(NAME):	$(LIBFT) $(OBJS)
		@ar -rcs $(NAME) $(OBJS)
		@echo "\033[32;1m\n>>	ft_printf READY\033[0m"

all:		$(NAME)

objects/%.o:	sources/%.c
		@mkdir -p objects
		$(CC)	$(CFLAGS)	-c	$<	-o	$@

$(LIBFT):
		@$(MAKE) bonus -C $(dir $(LIBFT))
		@cp $(LIBFT) $(NAME)
		@echo "\n"

clean:
		@$(MAKE) clean -C $(dir $(LIBFT))
		@echo "\033[31;1m"
		@$(RM) -v $(OBJS)
		@$(RM) -vd objects
		@echo "\033[0m"

fclean:		clean
		@$(MAKE) fclean -C $(dir $(LIBFT))
		@echo "\033[31;1m"
		@$(RM) -v $(NAME)
		@echo "\033[0m"

re:			fclean all

.PHONY: all clean fclean re
