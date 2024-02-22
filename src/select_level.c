/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:08:09 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/03 20:17:49 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	select_level_mouse_click_4(int button, int x, int y, t_args *vars)
{
	if (button == 1 && x > 147 && x < 447 && y > 655 && y < 733)
	{
		vars->map = vars->map_cluster[Level_10];
		vars->map_index = Level_10;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	if (button == 1 && x > 600 && x < 900 && y > 655 && y < 733)
	{
		vars->map = vars->map_cluster[Level_11];
		vars->map_index = Level_11;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	if (button == 1 && x > 1053 && x < 1353 && y > 655 && y < 733)
	{
		vars->map = vars->map_cluster[Level_12];
		vars->map_index = Level_12;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	select_level_mouse_click_5(button, x, y, vars);
}

void	select_level_mouse_click_3(int button, int x, int y, t_args *vars)
{
	if (button == 1 && x > 147 && x < 447 && y > 461 && y < 539)
	{
		vars->map = vars->map_cluster[Level_7];
		vars->map_index = Level_7;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	if (button == 1 && x > 600 && x < 900 && y > 461 && y < 539)
	{
		vars->map = vars->map_cluster[Level_8];
		vars->map_index = Level_8;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	if (button == 1 && x > 1053 && x < 1353 && y > 461 && y < 539)
	{
		vars->map = vars->map_cluster[Level_9];
		vars->map_index = Level_9;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	select_level_mouse_click_4(button, x, y, vars);
}

void	select_level_mouse_click_2(int button, int x, int y, t_args *vars)
{
	if (button == 1 && x > 147 && x < 447 && y > 267 && y < 345)
	{
		vars->map = vars->map_cluster[Level_4];
		vars->map_index = Level_4;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	if (button == 1 && x > 600 && x < 900 && y > 267 && y < 345)
	{
		vars->map = vars->map_cluster[Level_5];
		vars->map_index = Level_5;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	if (button == 1 && x > 1053 && x < 1353 && y > 267 && y < 345)
	{
		vars->map = vars->map_cluster[Level_6];
		vars->map_index = Level_6;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	select_level_mouse_click_3(button, x, y, vars);
}

int	select_level_mouse_click(int button, int x, int y, t_args *vars)
{
	if (button == 1 && x > 600 && x < 900 && y > 73 && y < 151)
	{
		vars->map = vars->map_cluster[Level_2];
		vars->map_index = Level_2;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	if (button == 1 && x > 1053 && x < 1353 && y > 73 && y < 151)
	{
		vars->map = vars->map_cluster[Level_3];
		vars->map_index = Level_3;
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	select_level_mouse_click_2(button, x, y, vars);
	return (0);
}

void	run_select_level_page(t_args *vars)
{
	int		i;
	int		j;
	void	*menu;

	vars->win = mlx_new_window(vars->mlx, 1500, 1000, "SELECT LEVEL");
	menu = mlx_xpm_file_to_image(
			vars->mlx, "textures/menu/SELECT_LEVEL.xpm", &j, &i);
	mlx_put_image_to_window(vars->mlx, vars->win, menu, 0, 0);
	mlx_hook(vars->win, ON_MOUSEDOWN, 1L << 0, select_level_mouse_click, vars);
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, key_movement, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 0, close_win, vars);
}
