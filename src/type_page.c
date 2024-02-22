/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_page.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 19:44:57 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/03 19:45:51 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_type_mouse_click(int button, int x, int y, t_args *vars)
{
	if (button == 1 && x > 374 && x < 1125 && y > 248 && y < 363)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		play_backgroud_music();
		run_game_page(vars);
	}
	if (button == 1 && x > 375 && x < 1125 && y > 419 && y < 534)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		run_select_level_page(vars);
	}
	if (button == 1 && x > 375 && x < 1125 && y > 591 && y < 706)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		run_main_page(vars);
	}
	return (0);
}

void	run_game_type_page(t_args *vars)
{
	int		i;
	int		j;
	void	*menu;

	vars->win = mlx_new_window(vars->mlx, 1500, 1000, "GAME TYPE");
	menu = mlx_xpm_file_to_image(
			vars->mlx, "textures/menu/GAME_TYPE.xpm", &j, &i);
	mlx_put_image_to_window(vars->mlx, vars->win, menu, 0, 0);
	mlx_hook(vars->win, ON_MOUSEDOWN, 1L << 0, game_type_mouse_click, vars);
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, key_movement, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 0, close_win, vars);
}
