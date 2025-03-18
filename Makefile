# Project: fdf
NAME = fdf
CC = cc
# CURRENT_DIR := $(shell pwd)/
CFLAGS = -Wall -Wextra -Werror -DCURRENT_DIR=\"$(CURRENT_DIR)\"
I := 3

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
	@$(eval I=$(shell echo $$(($(I)+1))))
	@echo "\e[32m[$(I)] [...Fdf...] Successfully compiled.\e[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ $(INCLUDES) -o $@
	@$(eval I=$(shell echo $$(($(I)+1))))
	@echo "[$(I)][ $^ ]   Bulding object files..."


gdb: CFLAGS += -g
gdb: re
	@gdb -tui --args ./fdf map.fdf
gnl:
	@make -C includes/gnl > /dev/null 2>&1
	@echo "[1][...gnl...] Successfully compiled."

ft_printf:
	@make -C includes/ft_printf > /dev/null 2>&1 || exit 1
	@echo  "[2][ft_Printf] Successfully compiled."

libft:
	@make -C includes/libft > /dev/null 2>&1 || exit 1
	@echo "[3][..Libft..] Successfully compiled."

clean:
	@make -C includes/gnl clean > /dev/null 2>&1
	@echo "[1][...gnl...] Cleaned."
	@make -C includes/ft_printf clean > /dev/null 2>&1
	@echo "[2][ft_Printf] Cleaned."
	@make -C includes/libft clean > /dev/null 2>&1
	@echo "[3][..Libft..] Cleaned."
	@rm -f $(OBJS)
	@echo "[4][...Fdf...] Object files removed."


fclean: clean
	@rm -f $(NAME)
	@echo  "\e[33m[5][...Fdf...] Fdf shut down.\e[0m"
	@echo ".................................." 

re: fclean all 

valgrind: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  ./fdf maps/test.fdf
	$(MAKE) clean

.PHONY: all clean fclean re ft_printf libft gnl
