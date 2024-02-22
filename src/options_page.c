/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_page.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:03:29 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 12:03:57 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	update_options_menu(t_args *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->menu_img, 0, 0);
	if (vars->skin_chooser == Skin_1)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->preview_player_imgs[Skin_1], 680, 370);
	if (vars->skin_chooser == Skin_2)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->preview_player_imgs[Skin_2], 680, 370);
	if (vars->skin_chooser == Skin_3)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->preview_player_imgs[Skin_3], 680, 370);
	if (vars->skin_chooser == Skin_4)
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->preview_player_imgs[Skin_4], 680, 370);
	return (0);
}

int	options_mouse_click(int button, int x, int y, t_args *vars)
{
	if (button == 1 && x > 56 && x < 169 && y > 442 && y < 556)
	{
		vars->skin_chooser--;
		if (vars->skin_chooser < 0)
			vars->skin_chooser = 3;
		update_options_menu(vars);
	}
	if (button == 1 && x > 1316 && x < 1430 && y > 442 && y < 556)
	{
		vars->skin_chooser++;
		if (vars->skin_chooser > 3)
			vars->skin_chooser = 0;
		update_options_menu(vars);
	}
	if (button == 1 && x > 376 && x < 1124 && y > 812 && y < 926)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		run_main_page(vars);
	}
	return (0);
}

void	run_options_page(t_args *vars)
{
	int	i;
	int	j;

	vars->win = mlx_new_window(vars->mlx, 1500, 1000, "OPTIONS");
	vars->menu_img = mlx_xpm_file_to_image(
			vars->mlx, "textures/menu/OPTIONS.xpm", &j, &i);
	update_options_menu(vars);
	mlx_hook(vars->win, ON_MOUSEDOWN, 1L << 0, options_mouse_click, vars);
	mlx_hook(vars->win, ON_KEYDOWN, 1L << 0, key_movement, vars);
	mlx_hook(vars->win, ON_DESTROY, 1L << 0, close_win, vars);
}
