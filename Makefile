# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 11:49:36 by mmartin-          #+#    #+#              #
#    Updated: 2020/08/09 12:59:52 by mmartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO_MSG	= @echo "\x1b[1;100;mget_next_line\x1b[0;90m $(2)$(1)...\x1b[0m"

GNL_D		= srcs
GNL_I		= includes

SRCS		= $(shell find $(GNL_D) -type f -name "*.c")
OBJS		= $(SRCS:.c=.o)

PATH		= $(shell pwd)
NAME		= libgnl.a

%.o : %.c
			@clang -Wall -Werror -Wextra -D BUFFER_SIZE=512 -c $< -o $@ -O3 -march=skylake

$(NAME):	$(OBJS)
			$(call ECHO_MSG,"compiling")
			@ar -rcs $(PATH)/$(NAME) $(OBJS)

all:		$(NAME)

# Deprecated, maintained for project integrity
bonus:		$(NAME)

clean:
			$(call ECHO_MSG,"deleting objects")
			@rm -f $(OBJS)

fclean:		clean
			$(call ECHO_MSG,"deleting library")
			@rm -f $(PATH)/$(NAME)

re:			fclean $(NAME)

.PHONY:		all bonus clean fclean re
