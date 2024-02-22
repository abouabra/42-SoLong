/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:52:42 by ayman             #+#    #+#             */
/*   Updated: 2023/01/04 14:33:38 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <time.h>

# ifndef BONUS
#  define BONUS 1
# endif

# define SPRITE_X 64
# define SPRITE_Y 64

# define PADDING 64

# define PLAYER_ANIMATION_TIMER 20
# define EXIT_ANIMATION_TIMER 10

# define COIN_ANIMATION_TIMER 5

# define ENEMY_MOVEMENT_TIMER 35
# define ENEMY_HEALTH 3

# define BULLET_MOVEMENT_TIMER 20
# define BULLET_MAGAZINE_SIZE 5

typedef struct s_bullet
{
	int				id;
	void			*img;
	int				prespective;
	int				x;
	int				y;
	struct s_bullet	*next;
}					t_bullet;

typedef struct s_enemy
{
	int				id;
	int				prespective;
	int				x;
	int				y;
	int				health;
	int				coin_x;
	int				coin_y;
	struct s_enemy	*next;
}					t_enemy;

typedef struct t_args
{
	void			*mlx;
	void			*win;

	int				movement_allowed;
	int				movement_keycode;

	void			*imgs[5];

	void			*all_player_imgs[4][4];

	void			*preview_player_imgs[4];
	void			*player_imgs[4];

	void			*zombie_imgs_paths[4];
	void			*zombie_imgs[4];

	void			*coin_imgs[8];
	int				coin_imgs_counter;

	void			*health_bar_imgs[3];

	void			*exit_imgs_paths[5];
	void			*exit_imgs[5];

	void			*default_player_img;
	void			*default_coin_img;
	void			*default_exit_img;
	int				exit_status;
	int				exit_tracker;

	int				clock_timer;
	int				coin_counter;
	int				bullet_counter;
	int				score_counter;

	int				movement_counter;
	char			**map;
	char			**map_clone;
	char			**map_cluster[12];
	int				vaid_path_counter;
	int				number_of_lines;
	int				line_len;
	int				player_pos[2];

	int				prespective;
	int				bullet_id;
	int				shoot;
	t_bullet		*bullet_head;
	t_bullet		*bullet;
	void			*bullet_img;

	int				mouse_x;
	int				mouse_y;

	int				screen_x;
	int				screen_y;

	int				map_index;
	void			*padding_menu_img;

	int				enemy_id;
	t_enemy			*enemy_head[12];
	t_enemy			*enemy;

	int				skin_chooser;
	void			*menu_img;

	int				x_calc;
	int				y_calc;
}					t_args;

char				**clone_map(t_args *vars);
int					map_check(t_args *vars, char *map_name);
int					map_operation(t_args *vars, char *map_name);
int					map_phase_1(char *map_name);
int					map_phase_2(t_args *vars, int *exit_count, int *coin_count,
						int *player_count);
int					map_phase_3(t_args *vars, int exit_count, int coin_count,
						int player_count);
int					map_phase_4(t_args *vars);
int					map_phase_5(t_args *vars);
int					map_phase_6(t_args *vars);
int					is_not_charset(char *str, char c);
void				free_map(t_args *vars, char **map);
void				load_assets(t_args *vars);
void				print_map(t_args *vars);
void				print_map_2(t_args *vars, int i, int j);
int					key_movement(int keycode, t_args *vars);
int					close_win(t_args *vars);
int					update_frames(t_args *vars);
void				move_player_up(t_args *vars);
void				move_player_down(t_args *vars);
void				move_player_left(t_args *vars);
void				move_player_right(t_args *vars);
void				check_before_print(t_args *vars);
void				render_extra_items(t_args *vars, int i, int j, char c);

// bonus
int					get_mouse_data(int x, int y, t_args *vars);
int					mouse_click(int button, int x, int y, t_args *vars);

void				bonus_animation(t_args *vars);
void				run_door_audio(void);
void				play_backgroud_music(void);

void				add_bullet_in_front(t_bullet **head, t_bullet *bullet);
t_bullet			*ft_new_bullet(t_args *vars);
void				delete_node(t_bullet **head, int id);

void				shoot(int clock_timer, t_args *vars);
void				clear_bullets(t_args *vars);

void				handle_game_menu(t_args *vars);

void				run_main_page(t_args *vars);
void				run_game_page(t_args *vars);
void				run_game_type_page(t_args *vars);
void				run_options_page(t_args *vars);
void				run_select_level_page(t_args *vars);

void				load_map_clusers(t_args *vars);
void				generated_map_valid_path(t_args *vars, char **map, int i,
						int j);
char				**generate_random_map(t_args *vars);
char				**clone_generated_map(t_args *vars, char **map);
char				**get_valid_map(t_args *vars);
void				initialize_map(t_args *vars, char **map);
void				place_walls(t_args *vars, char **map);
void				place_collectibles(t_args *vars, char **map);
int					coin_counter(t_args *vars, char **map);
void				place_exit(t_args *vars, char **map);
void				place_player(t_args *vars, char **map);

void				place_extra_items(t_args *vars, char **map);
void				place_enemy(t_args *vars, char **map);

t_enemy				*ft_new_enemy(t_args *vars, int i, int j);
t_enemy				*ft_last_enemy(t_enemy *enemy);
void				add_enemy_in_back(t_enemy **head, t_enemy *enemy);
void				update_enemy_pos(t_args *vars);
t_enemy				*get_enemy_node(t_args *vars, int x, int y);
void				delete_enemy_node(t_args *vars, t_enemy **head, int id);
void				ft_enemy_clear(t_enemy **head);

void				move_enemy(t_args *vars);
void				move_enemy_up(t_args *vars, t_enemy *enemy);
void				move_enemy_down(t_args *vars, t_enemy *enemy);
void				move_enemy_left(t_args *vars, t_enemy *enemy);
void				move_enemy_right(t_args *vars, t_enemy *enemy);

void				assign_coin_to_enemy(t_args *vars);

void				run_kill_enemy_audio(void);
void				run_shoot_bullet_audio(void);
void				run_exploation_audio(void);
void				hurt_enemy(t_args *vars, char c, int i, int j);

void				print_enemy_sprites(t_args *vars);
void				print_enemy_hp(t_args *vars);
void				set_player_assets(t_args *vars);

void				end_phase(t_args *vars);
void				select_level_mouse_click_5(int button, int x, int y,
						t_args *vars);
void				place_exit(t_args *vars, char **map);
void				place_player(t_args *vars, char **map);
void				place_extra_items_2(t_args *vars, char **map);
void				place_extra_items_3(t_args *vars, char **map);
void				place_walls_2(t_args *vars, char **map);
void				print_enemy_hp(t_args *vars);
void				get_all_player_assets(t_args *vars);
void				get_all_player_assets_2(t_args *vars);
void				get_all_player_assets_3(t_args *vars);
void				load_game_assets(t_args *vars);
void				get_coin_assets(t_args *vars);
void				get_zombie_assets(t_args *vars);
void				get_exit_assets(t_args *vars);

int					is_in_range_3_follow_up(t_args *vars, int x, int y);
int					is_in_range_3(t_args *vars, int x, int y);
int					is_in_range_2(t_args *vars, int x, int y);

enum
{
	X,
	Y,
};
enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
enum
{
	Skin_1,
	Skin_2,
	Skin_3,
	Skin_4
};
enum
{
	heath_33,
	heath_66,
	heath_100,
};
enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	Level_1,
	Level_2,
	Level_3,
	Level_4,
	Level_5,
	Level_6,
	Level_7,
	Level_8,
	Level_9,
	Level_10,
	Level_11,
	Level_12,
};

enum
{
	Collectibale_0,
	Collectibale_1,
	Collectibale_2,
	Collectibale_3,
	Collectibale_4,
	Collectibale_5,
	Collectibale_6,
	Collectibale_7
};

enum
{
	Exit_0,
	Exit_1,
	Exit_2,
	Exit_3,
	Exit_4,
};
enum
{
	Background,
	Extra_bg_0,
	Extra_bg_1,
	Extra_bg_2,
	Wall
};
#endif
