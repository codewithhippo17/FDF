# Project: fdf
NAME = fdf
CC = cc
CURRENT_DIR := $(shell pwd)/
CFLAGS = -Wall -Wextra -Werror -DCURRENT_DIR=\"$(CURRENT_DIR)\"

# fdf sources
SRCS =	fdf.c src/fdf_utils.c src/fdf_helpers.c\
		src/parssing.c src/parssing_utils.c src/parssing_helpers.c\
		src/fdf_scale.c\
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
		-L./includes/ft_printf\
		-L./includes/libft\
		-lmlx -lX11 -lXext -lft -lgnl -lftprintf -lm

all: gnl ft_printf libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "\033[1;92m[...Fdf...] Successfully compiled.\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ $(INCLUDES) -o $@
	@echo "[..$^..]   Bulding object files..."


gnl:
	@make -C includes/gnl 2>&1 | grep -q "Nothing to be done for 'all'" && \
	echo "[.....gnl.....] Nothing to be done for 'all'." || \
	echo "[.....gnl.....] Successfully compiled."

ft_printf:
	@make -C includes/ft_printf  2>&1 | grep -q "Nothing to be done for 'all'" && \
	echo "[..ft_printf..] Nothing to be done for 'all'." || \
	echo "[..ft_printf..] Successfully compiled."

libft:
	@make -C includes/libft  2>&1 | grep -q "Nothing to be done for 'all'" && \
	echo "[....Libft....] Nothing to be done for 'all'." || \
	echo "[....Libft....] Successfully compiled."

clean:
	@make -C includes/gnl clean > /dev/null 2>&1
	@echo "[...gnl...] Cleaned."
	@make -C includes/ft_printf clean > /dev/null 2>&1
	@echo "[ft_Printf] Cleaned."
	@make -C includes/libft clean > /dev/null 2>&1
	@echo "[..Libft..] Cleaned."
	@rm -f $(OBJS)
	@echo "[...Fdf...] Object files removed."


fclean:
	@make -C includes/gnl fclean > /dev/null 2>&1
	@echo "[...gnl...] Cleaned."
	@make -C includes/ft_printf fclean > /dev/null 2>&1
	@echo "[ft_Printf] Cleaned."
	@make -C includes/libft fclean > /dev/null 2>&1
	@echo "[..Libft..] Cleaned."
	@rm -f $(OBJS)
	@echo "[...Fdf...] Object files removed."
	@rm -f $(NAME)
	@echo  "\033[1;91m[...Fdf...] Fdf shuted down.\033[0m"

re: fclean all

gdb: CFLAGS += -g
gdb: re
	@gdb -tui --args ./fdf map.fdf

valgrind: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./fdf maps/42.fdf
	$(MAKE) clean

.PHONY: all clean fclean re ft_printf libft gnl
.SECONDARY : $(OBJS)