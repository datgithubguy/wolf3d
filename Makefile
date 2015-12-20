SRC = ft_main.c\
ft_dda.c\
ft_draw.c\
ft_draw2.c\
ft_free.c\
ft_getmap.c\
ft_init.c\
ft_menu_modes.c\
ft_mooves.c\
ft_give_texture.c\
ft_letters_to_tex.c\
ft_put_knife.c\
gnl/get_next_line.c\

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

OBJ = $(SRC:.c=.o)

.PHONY: re clean fclean all

all: $(NAME)

$(NAME): $(OBJ)
	@echo "     #####           "
	@echo "    #### _\_  ________"
	@echo "    ##=-[.].]| \      \ "
	@echo "    #(    _\ |  |------| "
	@echo "     #   __| |  |||||||| "
	@echo "      \  _/  |  ||||||||"
	@echo "   .--'--'-. |  | ____ |"
	@echo "  / __      \|__|[o__o]|"
	@echo "_(____nm_______ /____\____"

	make -C gnl/libft
	make -C minilibx_macos
	gcc -o $(NAME) $(SRC:.c=.o) -L ./gnl/libft -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit #-fsanitize=address -g

%.o: %.c
	gcc -c -o $@ $(FLAGS) $<

clean:
	@rm -rf $(SRC:.c=.o)

fclean: clean
	@make -C minilibx_macos clean
	@make -C gnl/libft fclean
	@rm -rf $(NAME)

re: fclean all

f: re
	./$(NAME)
