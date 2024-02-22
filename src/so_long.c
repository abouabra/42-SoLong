/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:35:02 by ayman             #+#    #+#             */
/*   Updated: 2023/01/03 19:50:01 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main_mouse_click(int button, int x, int y, t_args *vars)
{
	int	i;

	if (button == 1 && x > 374 && x < 1125 && y > 248 && y < 363)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		run_game_type_page(vars);
	}
	if (button == 1 && x > 375 && x < 1125 && y > 419 && y < 534)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		run_options_page(vars);
	}
	if (button == 1 && x > 375 && x < 1125 && y > 591 && y < 706)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		system("killall afplay &> /dev/null");
		i = -1;
		while (++i < 12)
			free_map(vars, vars->map_cluster[i]);
		free(vars);
		exit(0);
	}
	return (0);
}

void	update_player_pos(t_args *vars)
{
	int	i;
	int	j;

	vars->coin_counter = 0;
	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
		{
			if (vars->map[i][j] == 'P')
			{
				vars->player_pos[X] = j;
				vars->player_pos[Y] = i;
			}
			if (vars->map[i][j] == 'C')
				vars->coin_counter++;
		}
	}
	vars->score_counter = 0;
}

void	run_game_page(t_args *vars)
{
	vars->win = mlx_new_window(vars->mlx, vars->screen_x, vars->screen_y
			+ PADDING, "so_long");
	update_player_pos(vars);
	update_enemy_pos(vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 1L << 0, get_mouse_data, vars);
	mlx_hook(vars->win, ON_MOUSEDOWN, 1L << 0, mouse_click, vars);
	vars->bullet_counter = BULLET_MAGAZINE_SIZE;
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, key_movement, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 0, close_win, vars);
	mlx_loop_hook(vars->mlx, update_frames, vars);
}

void	run_main_page(t_args *vars)
{
	int		i;
	int		j;
	void	*menu;

	vars->win = mlx_new_window(vars->mlx, 1500, 1000, "MENU");
	load_assets(vars);
	menu = mlx_xpm_file_to_image(vars->mlx, "textures/menu/MAIN.xpm",
			&j, &i);
	mlx_put_image_to_window(vars->mlx, vars->win, menu, 0, 0);
	mlx_hook(vars->win, ON_MOUSEDOWN, 1L << 0, main_mouse_click, vars);
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, key_movement, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 0, close_win, vars);
}

int	main(int ac, char **av)
{
	t_args	*vars;

	if (ac != 2)
		return (0);
	vars = ft_calloc(1, sizeof(t_args));
	if (!vars)
		return (0);
	if (!map_check(vars, av[1]))
		return (0);
	load_map_clusers(vars);
	vars->mlx = mlx_init();
	vars->screen_y = vars->number_of_lines * SPRITE_X;
	vars->screen_x = vars->line_len * SPRITE_X;
	run_main_page(vars);
	mlx_loop(vars->mlx);
	end_phase(vars);
	return (0);
}
