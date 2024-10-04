# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkander <rkander@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 16:08:55 by rkander           #+#    #+#              #
#    Updated: 2024/07/14 19:34:31 by rkander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRC_CLIENT = client.c 
SRC_SERVER = server.c
HEADER = minitalk.h
CC = cc
FLAGS = -Wall -Wextra -Werror

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)



all: $(CLIENT) $(SERVER)

%.o : %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

$(CLIENT): $(OBJ_CLIENT)
		$(CC) $(FLAGS) $(OBJ_CLIENT) -o $(CLIENT)
$(SERVER): $(OBJ_SERVER)
		$(CC) $(FLAGS) $(OBJ_SERVER) -o $(SERVER)



bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
		$(RM) $(CLIENT) $(SERVER) 

re: fclean all

.PHONY: all clean fclean re bonus