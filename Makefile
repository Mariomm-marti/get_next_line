# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 15:21:05 by mmartin-          #+#    #+#              #
#    Updated: 2020/11/10 20:50:12 by mmartin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL_MSG		= @echo "\x1b[48;5;126m\x1b[38;5;15m\x1b[1m       gnl\x1b[0m\x1b[0;90m $(1)             \x1b[0m"

GNL_SRCS	= srcs/get_next_line.c \
			  srcs/get_next_line_utils.c
GNL_OBJS	= $(GNL_SRCS:.c=.o)

GNL_OUT		= "."
GNL_NAME	= libgnl.a

%.o : %.c
					@printf "\x1b[48;5;126m\x1b[38;5;15m\x1b[1m       gnl\x1b[0m\x1b[0;90m Compiling $@...                           \x1b[0m\r"
					@clang -Wall -Werror -Wextra -c $< -o $@ -O3 -march=skylake

$(GNL_NAME):	$(GNL_OBJS)
					$(call GNL_MSG,"Linking objects into $(GNL_OUT)/$(GNL_NAME)")
					@ar -rcs $(GNL_OUT)/$(GNL_NAME) $(GNL_OBJS)
					$(call GNL_MSG,"Finished linking","\n")

all:			$(GNL_NAME)

bonus:			$(GNL_NAME)

clean:
					$(call GNL_MSG,"Deleting all objects...","\n")
					@rm -f $(GNL_OBJS)

fclean:			clean
					$(call GNL_MSG,"Deleting $(GNL_OUT)/$(GNL_NAME)...","\n")
					@rm -f $(GNL_OUT)/$(GNL_NAME)

re:				fclean $(GNL_NAME)

.PHONY:			all bonus clean fclean re
