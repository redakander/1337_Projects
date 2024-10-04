# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkander <rkander@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 10:30:14 by rkander           #+#    #+#              #
#    Updated: 2024/07/12 12:15:27 by rkander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FLAGS		= -Wall -Wextra -Werror

CP			= cc

NAME		= push_swap

SFLS	= actions.c actions_b.c main.c parsing.c sort.c sort_100.c sort_reste.c utils.c

SRCS_DIR 	= srcs/

OBJS_DIR 	= objs_files/

OBJS 		= $(addprefix $(OBJS_DIR), $(SFLS:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CP) $(C_FLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c h_file/push_swap.h
		mkdir -p $(OBJS_DIR)
		cc $(C_FLAGS) -c $< -o $@ -MMD

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
		@rm -rf $(NAME)

re:	fclean all
.PHONY:	clean fclean all