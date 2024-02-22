
SRC = map_utils.c map_check.c  map_operation.c map_operation_2.c so_long.c load_assets.c load_assets_2.c \
		load_assets_3.c key_movement.c move_player.c update_frames.c mlx_utils.c render_extra_items.c \
		bonus_animation.c run_music.c mouse_movement.c bullet_linked_list_stuff.c shoot.c shoot_2.c handle_text.c \
		type_page.c select_level.c select_level_2.c options_page.c load_map_clusters.c generate_random_map.c \
		random_map_elements.c random_map_elements_2.c enemy.c enemy_linked_list_stuff.c enemy_linked_list_stuff_2.c enemy_movement.c enemy_movement_2.c

SRC_DIR = src/
OBJ_DIR = objs/

OSRC=$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

NAME = so_long
CFLAGS= -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit 
INCLUDE = -I libft -I minilibx

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RESET = \033[0m

all : ascii $(NAME)

$(NAME) : $(OSRC) 
	@make -C libft > /dev/null
	@$(CC) $(OSRC) $(CFLAGS) $(MLX_FLAGS) $(INCLUDE) minilibx/libmlx.a libft/libft.a -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@make -C libft clean
	@rm -rf $(OBJ_DIR)

fclean:
	@make -C libft fclean
	@rm -rf $(OBJ_DIR) $(NAME)

re: fclean all


ascii:
	@clear
	@printf "$(GREEN)\
                                                                                                                   \n\
                                                                                                                   \n\
   SSSSSSSSSSSSSSS                  LLLLLLLLLLL                                                                    \n\
 SS:::::::::::::::S                 L:::::::::L                                                                    \n\
S:::::SSSSSS::::::S                 L:::::::::L                                                                    \n\
S:::::S     SSSSSSS                 LL:::::::LL                                                                    \n\
S:::::S               ooooooooooo     L:::::L                  ooooooooooo   nnnn  nnnnnnnn       ggggggggg   ggggg\n\
S:::::S             oo:::::::::::oo   L:::::L                oo:::::::::::oo n:::nn::::::::nn    g:::::::::ggg::::g\n\
 S::::SSSS         o:::::::::::::::o  L:::::L               o:::::::::::::::on::::::::::::::nn  g:::::::::::::::::g\n\
  SS::::::SSSSS    o:::::ooooo:::::o  L:::::L               o:::::ooooo:::::onn:::::::::::::::ng::::::ggggg::::::gg\n\
    SSS::::::::SS  o::::o     o::::o  L:::::L               o::::o     o::::o  n:::::nnnn:::::ng:::::g     g:::::g \n\
       SSSSSS::::S o::::o     o::::o  L:::::L               o::::o     o::::o  n::::n    n::::ng:::::g     g:::::g \n\
            S:::::So::::o     o::::o  L:::::L               o::::o     o::::o  n::::n    n::::ng:::::g     g:::::g \n\
            S:::::So::::o     o::::o  L:::::L         LLLLLLo::::o     o::::o  n::::n    n::::ng::::::g    g:::::g \n\
SSSSSSS     S:::::So:::::ooooo:::::oLL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::o  n::::n    n::::ng:::::::ggggg:::::g \n\
S::::::SSSSSS:::::So:::::::::::::::oL::::::::::::::::::::::Lo:::::::::::::::o  n::::n    n::::n g::::::::::::::::g \n\
S:::::::::::::::SS  oo:::::::::::oo L::::::::::::::::::::::L oo:::::::::::oo   n::::n    n::::n  gg::::::::::::::g \n\
 SSSSSSSSSSSSSSS      ooooooooooo   LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo     nnnnnn    nnnnnn    gggggggg::::::g \n\
                                                                                                           g:::::g \n\
                                                                                               gggggg      g:::::g \n\
                                                                               $(RED)by: abouabra$(GREEN)    :::::gg   gg:::::g \n\
                                                                                                g::::::ggg:::::::g \n\
                                                                                                 gg:::::::::::::g  \n\
                                                                                                   ggg::::::ggg    \n\
                                                                                                      gggggg       \n\
                                                                                                            $(RESET)\n"
                                                                                                                                                                   



.PHONY: all clean fclean all
