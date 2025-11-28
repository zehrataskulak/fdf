NAME = fdf

CFLAGS =  -Wall -Wextra -Werror -lm

SRCS = main.c read_map.c window_settings.c find_isometric.c find_len.c put_dots_draw_lines.c scale_map.c\
		get_next_line/get_next_line_utils.c get_next_line/get_next_line.c 

OBJS = $(SRCS:.c=.o)

LIBS = libft/libft.a minilibx-linux/libmlx.a

all : $(LIBS) $(LIBS1) $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBS) -lX11 -lXext -o $(NAME)
	rm -f *.o

$(LIBS):
	make -C libft
	make -C minilibx-linux

clean:
	make clean -C libft
	make clean -C minilibx-linux
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

