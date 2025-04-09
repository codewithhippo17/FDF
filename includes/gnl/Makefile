CFILES = get_next_line.c get_next_line_utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OFILES = $(CFILES:.c=.o)

NAME = libgnl.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $@ $^


%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY : $(OFILES)
