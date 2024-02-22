/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:59:10 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/04 13:14:28 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map_2(t_args *vars, int i, int j)
{
	if (vars->map[i][j] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->imgs[Background], j * SPRITE_X, i * SPRITE_Y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->default_coin_img, j * SPRITE_X, i * SPRITE_Y);
	}
	if (vars->map[i][j] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->imgs[Background], j * SPRITE_X, i * SPRITE_Y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->default_exit_img, j * SPRITE_X, i * SPRITE_Y);
	}
	if (vars->map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->imgs[Background], j * SPRITE_X, i * SPRITE_Y);
	if (vars->map[i][j] == 'O')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->imgs[Background], j * SPRITE_X, i * SPRITE_Y);
	if (vars->map[i][j] == 'X' || vars->map[i][j] == 'Y' ||
		vars->map[i][j] == 'Z')
		render_extra_items(vars, i, j, vars->map[i][j]);
}

void	print_map(t_args *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < vars->number_of_lines)
	{
		j = -1;
		while (++j < vars->line_len)
		{
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->imgs[Background], j * SPRITE_X, i * SPRITE_Y);
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[Wall],
					j * SPRITE_X, i * SPRITE_Y);
			print_map_2(vars, i, j);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->default_player_img,
		vars->player_pos[X] * SPRITE_X, vars->player_pos[Y] * SPRITE_Y);
}

void	get_all_player_assets_3(t_args *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	vars->preview_player_imgs[Skin_1] = mlx_xpm_file_to_image(
			vars->mlx, "textures/preview/Preview_0.xpm", &x, &y);
	vars->preview_player_imgs[Skin_2] = mlx_xpm_file_to_image(
			vars->mlx, "textures/preview/Preview_1.xpm", &x, &y);
	vars->preview_player_imgs[Skin_3] = mlx_xpm_file_to_image(
			vars->mlx, "textures/preview/Preview_2.xpm", &x, &y);
	vars->preview_player_imgs[Skin_4] = mlx_xpm_file_to_image(
			vars->mlx, "textures/preview/Preview_3.xpm", &x, &y);
}

void	get_all_player_assets_2(t_args *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	vars->all_player_imgs[Skin_3][UP] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_3/Player_up.xpm", &x, &y);
	vars->all_player_imgs[Skin_3][DOWN] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_3/Player_down.xpm", &x, &y);
	vars->all_player_imgs[Skin_3][LEFT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_3/Player_left.xpm", &x, &y);
	vars->all_player_imgs[Skin_3][RIGHT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_3/Player_right.xpm", &x, &y);
	vars->all_player_imgs[Skin_4][UP] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_4/Player_up.xpm", &x, &y);
	vars->all_player_imgs[Skin_4][DOWN] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_4/Player_down.xpm", &x, &y);
	vars->all_player_imgs[Skin_4][LEFT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_4/Player_left.xpm", &x, &y);
	vars->all_player_imgs[Skin_4][RIGHT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_4/Player_right.xpm", &x, &y);
	get_all_player_assets_3(vars);
}

void	get_all_player_assets(t_args *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	vars->all_player_imgs[Skin_1][UP] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_1/Player_up.xpm", &x, &y);
	vars->all_player_imgs[Skin_1][DOWN] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_1/Player_down.xpm", &x, &y);
	vars->all_player_imgs[Skin_1][LEFT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_1/Player_left.xpm", &x, &y);
	vars->all_player_imgs[Skin_1][RIGHT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_1/Player_right.xpm", &x, &y);
	vars->all_player_imgs[Skin_2][UP] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_2/Player_up.xpm", &x, &y);
	vars->all_player_imgs[Skin_2][DOWN] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_2/Player_down.xpm", &x, &y);
	vars->all_player_imgs[Skin_2][LEFT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_2/Player_left.xpm", &x, &y);
	vars->all_player_imgs[Skin_2][RIGHT] = mlx_xpm_file_to_image(
			vars->mlx, "textures/player/skin_2/Player_right.xpm", &x, &y);
	get_all_player_assets_2(vars);
}
