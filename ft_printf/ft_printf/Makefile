NAME= libftprintf.a
CC= cc
CFLAGS= -Wall -Wextra -Werror
SRC= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_printexa.c ft_print_address.c ft_print_u.c
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean