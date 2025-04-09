# Project: fdf
NAME = fdf
CC = cc
CURRENT_DIR := $(shell pwd)/
CFLAGS = -Wall -Wextra -Werror -DCURRENT_DIR=\"$(CURRENT_DIR)\" -g

# fdf sources
SRCS =	fdf.c\
		src/fdf_init.c\
		src/parssing.c\
		src/fdf_helpers.c\
		src/fdf_scale.c\
		src/fdf_hook.c\
		src/parssing_utils.c\
		src/parssing_helpers.c\
		src/fdf_draw.c\
		src/kill.c
	
OBJS = $(SRCS:.c=.o)


# includes && libs
INCLUDES =	-I/usr/include/minilibx-linux\
			-I./includes\
			-I/usr/include/X11

MLX = -lmlx -lX11 -lXext

LIBS =	-L/usr/include/minilibx-linux\
		-L./includes/gnl\
		-L./includes/libft\
		-lmlx -lX11 -lXext -lft -lgnl -lmlx -lm

LIBFT = ./includes/libft/libft.a
LIBGNL = ./includes/gnl/libgnl.a

all: $(NAME)

$(NAME): $(LIBGNL) $(LIBFT) $(OBJS) ./includes/fdf.h
	@$(CC) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "\033[1;92m[...Fdf...] Successfully compiled.\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ $(INCLUDES) -o $@
	@echo "[..$^..]   Bulding object files..."

$(LIBGNL):
	@make -C includes/gnl 2>&1 | grep -q "Nothing to be done for 'all'" && \
	echo "[.....gnl.....] Nothing to be done for 'gnl'." || \
	echo "[.....gnl.....] Successfully compiled."

$(LIBFT):
	@make -C includes/libft  2>&1 | grep -q "Nothing to be done for 'all'" && \
	echo "[....Libft....] Nothing to be done for 'libft'." || \
	echo "[....Libft....] Successfully compiled."

clean:
	@make -C includes/gnl clean > /dev/null 2>&1
	@echo "[...gnl...] Cleaned."
	@make -C includes/libft clean > /dev/null 2>&1
	@echo "[..Libft..] Cleaned."
	@rm -f $(OBJS)
	@echo "[...Fdf...] Object files removed."

fclean:
	@make -C includes/gnl fclean > /dev/null 2>&1
	@echo "[...gnl...] Cleaned."
	@make -C includes/libft fclean > /dev/null 2>&1
	@echo "[..Libft..] Cleaned."
	@rm -f $(OBJS)
	@echo "[...Fdf...] Object files removed."
	@rm -f $(NAME)
	@echo  "\033[1;91m[...Fdf...] Fdf shuted down.\033[0m"

re: fclean all

.PHONY: all clean fclean re
.SECONDARY : $(OBJS)
