CFILES = 	ft_printf.c\
			helpers.c\
			n_out_helpers.c\
			put_helpers.c\
			s_out_helpers.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

OFILES = $(CFILES:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $^

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re